#include <iostream>
#include <optional>
#include <string>
#include <cmath>

#include "interpreter.hpp"

namespace Cellbot {

Interpreter::Interpreter(Simulation sim) : sim(sim) {
    enter_scope();
}

std::optional<std::unique_ptr<Node>> Interpreter::evaluate(const Node& node) {
    switch (node.type) {
        // blocks inside cases needed to fix switch_into_protected_scope error
        case Node::Type::identifier: {
            std::optional<std::unique_ptr<Node>*> var
                = var_find(std::get<std::string>(node.value));

            if (var) {
                if ((**var)->type == Node::Type::func_decl) {
                    report(node.location,
                           "can't use function here");
                }

                return std::make_unique<Node>(***var);
            }
            else {
                report(node.location, "undefined variable");
            }
        }


        case Node::Type::integer: {
            break;
        }


        case Node::Type::boolean: {
            break;
        }


        case Node::Type::massive: {
            auto result
                = std::make_unique<Node>(Node::Type::massive, node.location);

            result->children.reserve(node.children.size());
            for (auto& child : node.children) {
                auto evaluated = evaluate(*child);

                if (!evaluated) {
                    report(child->location, "expected value, got nothing");
                }

                result->children.push_back(std::move(*evaluated));
            }

            return result;
        }


        case Node::Type::logical_or: {
            for (auto& child : node.children) {
                std::unique_ptr<Node> evaluated
                    = evaluate_and_get_boolean(*child);

                if (std::get<bool>(evaluated->value) == true) {
                    return std::make_unique<Node>(Node::Type::boolean, true,
                                                  node.location);
                }
            }

            return std::make_unique<Node>(Node::Type::boolean,
                                          false, node.location);
        }


        case Node::Type::logical_and: {
            for (auto& child : node.children) {
                std::unique_ptr<Node> evaluated
                    = evaluate_and_get_boolean(*child);

                if (std::get<bool>(evaluated->value) == false) {
                    return std::make_unique<Node>(Node::Type::boolean, false,
                                                  node.location);
                }
            }

            return std::make_unique<Node>(Node::Type::boolean,
                                          true, node.location);
        }


        case Node::Type::equal: {
            std::optional<std::unique_ptr<Node>> lhand
                = evaluate(*node.children[0]);

            if (!lhand) {
                report(node.children[0]->location, 
                       "expected value, got nothing");
            }

            if ((*lhand)-> type != Node::Type::integer
             && (*lhand)-> type != Node::Type::boolean) {
                report(node.children[0]->location,
                       "invalid type");
            }

            std::optional<std::unique_ptr<Node>> rhand
                = evaluate(*node.children[1]);

            if (!rhand) {
                report(node.children[1]->location, 
                       "expected value, got nothing");
            }

            if ((*rhand)-> type != Node::Type::integer
             && (*rhand)-> type != Node::Type::boolean) {
                report(node.children[1]->location,
                       "invalid type");
            }

            if ((*lhand)->type != (*rhand)->type) {
                return std::make_unique<Node>(Node::Type::boolean,
                                              false, node.location);
            }

            if ((*lhand)->value != (*rhand)->value) {
                return std::make_unique<Node>(Node::Type::boolean,
                                              false, node.location);
            }

            return std::make_unique<Node>(Node::Type::boolean,
                                          true, node.location);
        }


        case Node::Type::not_equal: {
            std::optional<std::unique_ptr<Node>> lhand
                = evaluate(*node.children[0]);

            if (!lhand) {
                report(node.children[0]->location, 
                       "expected value, got nothing");
            }

            if ((*lhand)-> type != Node::Type::integer
             && (*lhand)-> type != Node::Type::boolean) {
                report(node.children[0]->location,
                       "invalid type");
            }

            std::optional<std::unique_ptr<Node>> rhand
                = evaluate(*node.children[1]);

            if (!rhand) {
                report(node.children[1]->location, 
                       "expected value, got nothing");
            }

            if ((*rhand)-> type != Node::Type::integer
             && (*rhand)-> type != Node::Type::boolean) {
                report(node.children[1]->location,
                       "invalid type");
            }

            if ((*lhand)->type == (*rhand)->type) {
                if ((*lhand)->value == (*rhand)->value) {
                    return std::make_unique<Node>(Node::Type::boolean,
                                                  false, node.location);
                }
            }

            return std::make_unique<Node>(Node::Type::boolean,
                                          true, node.location);
        }


        case Node::Type::more_than: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::boolean,
                std::get<long long>(lhand->value) > std::get<long long>(rhand->value),
                node.location);
        }


        case Node::Type::less_than: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::boolean,
                std::get<long long>(lhand->value) < std::get<long long>(rhand->value),
                node.location);
        }


        case Node::Type::addition: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::integer,
                std::get<long long>(lhand->value) + std::get<long long>(rhand->value),
                node.location);
        }


        case Node::Type::subtraction: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::integer,
                std::get<long long>(lhand->value) - std::get<long long>(rhand->value),
                node.location);
        }


        case Node::Type::multiplication: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::integer,
                std::get<long long>(lhand->value) * std::get<long long>(rhand->value),
                node.location);
        }


        case Node::Type::pow: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::integer,
                static_cast<long long>(std::pow(std::get<long long>(lhand->value), std::get<long long>(rhand->value))),
                node.location);
        }


        case Node::Type::division: {
            std::unique_ptr<Node> lhand
                = evaluate_and_get_integer(*node.children[0]);

            std::unique_ptr<Node> rhand
                = evaluate_and_get_integer(*node.children[1]);

            return std::make_unique<Node>(Node::Type::integer,
                std::get<long long>(lhand->value) / std::get<long long>(rhand->value),
                node.location);
        }


        case Node::Type::subscript: {
            std::unique_ptr<Node> massive
                = evaluate_and_get_massive(*node.children[0]);

            long long index = std::get<long long>(
                evaluate_and_get_integer(*node.children[1])->value);

            if (index < 0
             || static_cast<size_t>(index) >= massive->children.size()) {
                report(node.children[1]->location,
                       "index out of bounds");
            }

            return std::make_unique<Node>(
                *(massive->children[static_cast<size_t>(index)]));
        }

        case Node::Type::typecheck: {
            std::vector<Node::Type> args;
            args.reserve(node.children.size());

            for (auto& child : node.children) {
                Node::Type type;

                if (child->type == Node::Type::type) {
                    std::string type_str
                        = std::get<std::string>(child->value);
                    if (type_str == "integer") {
                        type = Node::Type::integer;
                    }
                    else if (type_str == "boolean") {
                        type = Node::Type::boolean;
                    }
                    else if (type_str == "massive") {
                        type = Node::Type::massive;
                    }
                    else {
                        report(child->location,
                               "unknown type");
                    }
                }
                else {
                    std::optional<std::unique_ptr<Node>> evaluated
                        = evaluate(*child);

                    if (evaluated) {
                        type = (*evaluated)->type;
                    }
                    else {
                        report(child->location,
                               "expected value, got nothing");
                    }
                }

                args.push_back(type);
            }

            return std::make_unique<Node>(Node::Type::boolean,
                args[0] == args[1],
                node.location);
        }

        case Node::Type::negation: {
            std::unique_ptr<Node> val
                = evaluate_and_get_integer(*node.children[0]);

            return std::make_unique<Node>(Node::Type::integer,
                -std::get<long long>(val->value),
                node.location);
        }


        case Node::Type::logical_not: {
            std::unique_ptr<Node> val
                = evaluate_and_get_boolean(*node.children[0]);

            return std::make_unique<Node>(Node::Type::boolean,
                !std::get<bool>(val->value),
                node.location);
        }


        case Node::Type::size: {
            std::unique_ptr<Node> val
                = evaluate_and_get_massive(*node.children[0]);

            return std::make_unique<Node>(Node::Type::integer,
                static_cast<long long>(val->children.size()),
                node.location);
        }


        case Node::Type::func_call: {
            std::optional<std::unique_ptr<Node>*> maybe_func
                = var_find(std::get<std::string>(node.children[0]->value));

            if (!maybe_func) {
                report(node.children[0]->location,
                       "undefined function");
            }

            if ((**maybe_func)->type != Node::Type::func_decl) {
                report(node.children[0]->location,
                       "not a function");
            }

            std::unique_ptr<Node>& func = **maybe_func;

            const std::vector<std::unique_ptr<Node>>& parameters
                = func->children[2]->children;
            const std::vector<std::unique_ptr<Node>>& arguments
                = node.children;

            std::vector<std::pair<std::string, std::unique_ptr<Node>>> vars;

            if (arguments.size() - 1 != parameters.size() / 2) {
                report(node.location,
                       "incorrect argument count");
            }

            vars.reserve(arguments.size() - 1);

            for (size_t i = 0; i < node.children.size() - 1; i++) {
                std::string par_type_str
                    = std::get<std::string>(parameters[i * 2]->value);
                std::string par_name
                    = std::get<std::string>(parameters[i * 2 + 1]->value);

                if (par_name == "result") {
                    report(parameters[i * 2 + 1]->location,
                           "can't have parameter named result");
                }

                for (size_t j = i * 2 + 3; j < parameters.size(); j += 2) {
                    if (par_name == std::get<std::string>(parameters[j]->value)) {
                        report(parameters[j]->location,
                               "duplicate parameter name");
                    }
                }

                std::unique_ptr<Node> arg_value;

                if (par_type_str == "integer") {
                    arg_value = evaluate_and_get_integer(*arguments[i + 1]);
                }
                else if (par_type_str == "boolean") {
                    arg_value = evaluate_and_get_boolean(*arguments[i + 1]);
                }
                else if (par_type_str == "massive") {
                    arg_value = evaluate_and_get_massive(*arguments[i + 1]);
                }
                else {
                    report(node.children[0]->location,
                           "unknown parameter type");
                }

                vars.push_back(std::pair<std::string, std::unique_ptr<Node>>
                    (par_name, std::move(arg_value)));
            }

            enter_scope(true);

            std::string return_type_str
                = std::get<std::string>(func->children[0]->value);
            if (return_type_str == "integer") {
                var_assign("result", std::make_unique<Node>(
                    Node::Type::integer, 0, yy::location()));
            }
            else if (return_type_str == "boolean") {
                var_assign("result", std::make_unique<Node>(
                    Node::Type::boolean, false, yy::location()));
            }
            else if (return_type_str == "massive") {
                var_assign("result", std::make_unique<Node>(
                    Node::Type::massive, yy::location()));
            }
            else if (return_type_str == "void") {}
            else {
                report(node.children[0]->location,
                       "unknown return type");
            }

            for (auto& var : vars) {
                var_assign(var.first, std::move(var.second));
            }

            evaluate(*func->children[3]);

            std::optional<std::unique_ptr<Node>*> p_result
                = var_find("result");

            std::optional<std::unique_ptr<Node>> result;

            if (p_result) {
                result = std::make_unique<Node>(***p_result);
            }
            else {
                result = {};
            }

            exit_scope();

            if (result) {
                return std::move(*result);
            }
            else {
                return {};
            }
        }


        case Node::Type::stmts: {
            for (auto& child : node.children) {
                if (child->type == Node::Type::func_decl) {
                    std::string func_name =
                        std::get<std::string>(child->children[1]->value);

                    if (var_find(func_name)) {
                        report(child->children[1]->location,
                               "name already taken");
                    }

                    var_assign(func_name, std::make_unique<Node>(*child));
                }
            }

            for (auto& child : node.children) {
                auto res = evaluate(*child);
            }

            return {};
        }


        case Node::Type::var_decl: {
            std::string var_type_str
                = std::get<std::string>(node.children[0]->value);

            std::string var_name
                = std::get<std::string>(node.children[1]->value);

            if (var_find(var_name)) {
                report(node.children[0]->location,
                       "name already taken");
            }

            Node::Type var_type;
            if (var_type_str == "integer") {
                var_type = Node::Type::integer;

                if (node.children.size() == 3) {
                    std::unique_ptr<Node> initializer
                        = evaluate_and_get_integer(*node.children[2]);

                    if (initializer->type != var_type) {
                        report(node.children[2]->location,
                               "unexpected initializer type");
                    }

                    var_assign(var_name, std::move(initializer));
                }
                else {
                    var_assign(var_name,
                        std::make_unique<Node>(var_type, 0, yy::location()));
                }
            }
            else if (var_type_str == "boolean") {
                var_type = Node::Type::boolean;

                if (node.children.size() == 3) {
                    std::unique_ptr<Node> initializer
                        = evaluate_and_get_boolean(*node.children[2]);

                    if (initializer->type != var_type) {
                        report(node.children[2]->location,
                               "unexpected initializer type");
                    }

                    var_assign(var_name, std::move(initializer));
                }
                else {
                    var_assign(var_name,
                        std::make_unique<Node>(var_type, false, yy::location()));
                }
            }
            else if (var_type_str == "massive") {
                var_type = Node::Type::massive;

                if (node.children.size() == 3) {
                    std::unique_ptr<Node> initializer
                        = evaluate_and_get_massive(*node.children[2]);

                    var_assign(var_name, std::move(initializer));
                }
                else {
                    var_assign(var_name,
                        std::make_unique<Node>(var_type, yy::location()));
                }
            }
            else {
                report(node.children[0]->location,
                       "unknown variable type");
            }

            return {};
        }


        case Node::Type::assignment: {
            switch (node.children[0]->type) {
                case Node::Type::identifier: {
                    std::string var_name
                        = std::get<std::string>(node.children[0]->value);

                    std::optional<std::unique_ptr<Node>*> var
                        = var_find(var_name);

                    if (!var) {
                        report(node.children[0]->location,
                               "undefined variable");
                    }

                    Node::Type var_type = (**var)->type;

                    std::unique_ptr<Node> value;
                    switch (var_type) {
                        case Node::Type::boolean:
                            value = evaluate_and_get_boolean(
                                    *node.children[1]);
                            break;
                        case Node::Type::integer:
                            value = evaluate_and_get_integer(
                                    *node.children[1]);
                            break;
                        case Node::Type::massive:
                            value = evaluate_and_get_massive(
                                    *node.children[1]);
                            break;
                        case Node::Type::func_decl:
                            report(node.location,
                                   "can't assign to function");
                            break;
                        default:
                            std::cerr << "PANIC!!!\n";
                            exit(1);
                    }

                    if (var_type != value->type) {
                        report(node.children[1]->location,
                               "invalid assignment value type");
                    }

                    var_assign(var_name, std::move(value));

                    break;
                }
                case Node::Type::subscript: {
                    std::unique_ptr<Node>* massive;
                    std::vector<long long> indices;

                    for (const std::unique_ptr<Node>* cur = &node.children[0];;) {
                        if ((*cur)->type == Node::Type::identifier) {
                            std::optional<std::unique_ptr<Node>*> var
                                = var_find(std::get<std::string>((*cur)->value));

                            if (var) {
                                massive = *var;
                            }
                            else {
                                report((*cur)->location, "undefined variable");
                                exit(1); // unnecessary, but prevents a compiler warning
                            }

                            break;
                        }

                        indices.push_back(std::get<long long>(
                            evaluate_and_get_integer(
                                *(*cur)->children[1])->value));

                        cur = &(*cur)->children[0];
                    }

                    std::unique_ptr<Node>* target = massive;
                    for (size_t i = indices.size(); i-- > 0;) {
                        if ((*target)->type != Node::Type::massive) {
                            report(node.children[0]->location,
                                   "invalid type, expecting array");
                        }

                        if (indices[i] < 0) {
                            report(node.children[0]->location,
                                   "index out of bounds");
                        }
                        else if (i == 0
                             && static_cast<size_t>(indices[i])
                             == (*target)->children.size()) {
                            (*target)->children.push_back(
                                std::unique_ptr<Node>());
                        }
                        else if (static_cast<size_t>(indices[i]) 
                             >= (*target)->children.size()) {
                            report(node.children[0]->location,
                                   "index out of bounds");
                        }

                        target = &(*target)->children[
                            static_cast<size_t>(indices[i])];
                    }

                    std::optional<std::unique_ptr<Node>> value
                        = evaluate(*node.children[1]);

                    if (!value) {
                        report(node.children[1]->location,
                               "expected value, got nothing");
                    }

                    *target = std::move(*value);

                    break;
                }
                default:
                    report(node.children[0]->location, "invalid assignee");
            }

            return {};
        }


        case Node::Type::func_decl: {
            // ignored when evaluated
            // the functions are declared by the stmts case
            return {};
        }


        case Node::Type::if_stmt: {
            std::unique_ptr<Node> condition
                = evaluate_and_get_boolean(*node.children[0]);

            if (std::get<bool>(condition->value)) {
                enter_scope();
                evaluate(*node.children[1]);
                exit_scope();
            }
            else if (node.children.size() == 3) {
                enter_scope();
                evaluate(*node.children[2]);
                exit_scope();
            }

            return {};
        }


        case Node::Type::loop_stmt: {
            std::string iter_name
                = std::get<std::string>(node.children[0]->value);

            if (var_find(iter_name)) {
                report(node.children[0]->location,
                       "name already taken");
            }

            long long start = std::get<long long>(
                evaluate_and_get_integer(*node.children[1])->value);

            long long stop = std::get<long long>(
                evaluate_and_get_integer(*node.children[2])->value);

            for (long long i = start; i < stop; i++) {
                enter_scope();

                var_assign(iter_name,
                    std::make_unique<Node>(Node::Type::integer,
                    i, node.children[0]->location));

                evaluate(*node.children[3]);

                exit_scope();
            }

            return {};
        }


        case Node::Type::while_stmt: {
            while (std::get<bool>(evaluate_and_get_boolean(*node.children[0])->value)) {
                enter_scope();
                evaluate(*node.children[1]);
                exit_scope();
            }

            return {};
        }


        case Node::Type::print: {
            std::optional<std::unique_ptr<Node>> value
                = evaluate(*node.children[0]);

            if (value) {
                std::cout << (*value)->as_string() << "\n";
            }
            else {
                report(node.children[0]->location,
                       "expected value, got nothing");
            }

            return {};
        }


        case Node::Type::control_sequence: {
            std::unique_ptr<Node> result
                = std::make_unique<Node>(Node::Type::massive, node.location);

            for (auto& child : node.children) {
                switch (child->type) {
                    case Node::Type::mfwd: {
                        sim.move(Simulation::Direction::forward);
                        break;
                    }
                    case Node::Type::mbwd: {
                        sim.move(Simulation::Direction::backward);
                        break;
                    }
                    case Node::Type::mlft: {
                        sim.move(Simulation::Direction::left);
                        break;
                    }
                    case Node::Type::mrgt: {
                        sim.move(Simulation::Direction::right);
                        break;
                    }
                    case Node::Type::lfwd: {
                        result->children.push_back(std::make_unique<Node>(
                            Node::Type::integer,
                            static_cast<long long>(sim.look(Simulation::Direction::forward)),
                            child->location));
                        break;
                    }
                    case Node::Type::lbwd: {
                        result->children.push_back(std::make_unique<Node>(
                            Node::Type::integer,
                            static_cast<long long>(sim.look(Simulation::Direction::backward)),
                            child->location));
                        break;
                    }
                    case Node::Type::llft: {
                        result->children.push_back(std::make_unique<Node>(
                            Node::Type::integer,
                            static_cast<long long>(sim.look(Simulation::Direction::left)),
                            child->location));
                        break;
                    }
                    case Node::Type::lrgt: {
                        result->children.push_back(std::make_unique<Node>(
                            Node::Type::integer,
                            static_cast<long long>(sim.look(Simulation::Direction::right)),
                            child->location));
                        break;
                    }
                    case Node::Type::chck: {
                        std::unique_ptr<Node> pos = std::make_unique<Node>(
                            Node::Type::massive,
                            child->location);

                        pos->children.push_back(std::make_unique<Node>(
                            Node::Type::integer,
                            static_cast<long long>(sim.bot_x),
                            child->location));

                        pos->children.push_back(std::make_unique<Node>(
                            Node::Type::integer,
                            static_cast<long long>(sim.bot_y),
                            child->location));

                        result->children.push_back(std::move(pos));

                        break;
                    }
                    case Node::Type::stop: {
                        if (result->children.size() > 0) {
                            std::unique_ptr<Node>& last = result->children.back();
                            if (last->type == Node::Type::integer) {
                                if (std::get<long long>(last->value) == 0) {
                                    goto end_loop;
                                }
                            }
                        }

                        break;
                    }
                    default:
                        report(child->location,
                               "unrecognized control operator");
                }
            }
            end_loop:

            return result;
        }


        default:
            report(node.location, "unknown AST node type");
    }

    return std::make_unique<Node>(node);
}

void Interpreter::enter_scope(bool function) {
    environment.push_front(std::pair<std::map<std::string, std::unique_ptr<Node>>, bool>());
    environment.front().second = function;
}

std::optional<std::unique_ptr<Node>*> Interpreter::var_find(std::string name) {
    for (auto& scope : environment) {
        auto var = scope.first.find(name);

        if (var == scope.first.end()) {
            if (scope.second) {
                break;
            }
            else {
                continue;
            }
        }

        return &var->second;
    }

    return {};
}

void Interpreter::var_assign(std::string name, std::unique_ptr<Node> value) {
    auto var = var_find(name);

    if (var) {
        **var = std::move(value);
    }
    else {
        environment.front().first[name] = std::move(value);
    }
}

void Interpreter::exit_scope() {
    environment.pop_front();
}

std::unique_ptr<Node> Interpreter::to_boolean(std::unique_ptr<Node> node) const {
    if (node->type == Node::Type::integer) {
        if (std::get<long long>(node->value) == 0) {
            return std::make_unique<Node>(Node::Type::boolean, false,
                                          node->location);
        }
        else {
            return std::make_unique<Node>(Node::Type::boolean, true,
                                          node->location);
        }
    }

    return node;
}

std::unique_ptr<Node> Interpreter::to_integer(std::unique_ptr<Node> node) const {
    if (node->type == Node::Type::boolean) {
        if (std::get<bool>(node->value) == true) {
            return std::make_unique<Node>(Node::Type::integer, 1,
                                          node->location);
        }
        else {
            return std::make_unique<Node>(Node::Type::integer, 0,
                                          node->location);
        }
    }

    return node;
}

std::unique_ptr<Node> Interpreter::evaluate_and_get_boolean(const Node& node) {
    std::optional<std::unique_ptr<Node>> result
        = evaluate(node);

    if (!result) {
        report(node.location, 
               "expected value, got nothing");
    }

    result = to_boolean(std::move(*result));

    if ((*result)->type != Node::Type::boolean) {
        report(node.location, 
               "invalid type, expected boolean");
    }

    return std::move(*result);
}

std::unique_ptr<Node> Interpreter::evaluate_and_get_integer(const Node& node) {
    std::optional<std::unique_ptr<Node>> result
        = evaluate(node);

    if (!result) {
        report(node.location, 
               "expected value, got nothing");
    }

    result = to_integer(std::move(*result));

    if ((*result)->type != Node::Type::integer) {
        report(node.location, 
               "invalid type, expected integer");
    }

    return std::move(*result);
}

std::unique_ptr<Node> Interpreter::evaluate_and_get_massive(const Node& node) {
    std::optional<std::unique_ptr<Node>> result
        = evaluate(node);

    if (!result) {
        report(node.location, 
               "expected value, got nothing");
    }

    if ((*result)->type != Node::Type::massive) {
        report(node.location, 
               "invalid type, expected massive");
    }

    return std::move(*result);
}

void Interpreter::report(const yy::location& loc, std::string error_text) const {
    std::cerr << loc << ": " + error_text + "\n";
    exit(1);
}

}
