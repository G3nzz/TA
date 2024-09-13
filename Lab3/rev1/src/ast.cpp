#include <stdexcept>
#include <variant>

#include "ast.hpp"

namespace Cellbot {

Node::Node(const Node& other) : type(other.type), value(other.value), location(other.location) {
    children.reserve(other.children.size());

    for (auto& child : other.children) {
        children.push_back(std::make_unique<Node>(*child));
    }
}

Node::Node(Node::Type type, yy::location loc) : type(type), location(loc) {}

Node::Node(Type type, ValueTypes value, yy::location loc) : type(type),
                                                            location(loc) {
    const std::string error_message = "invalid value type for node type";

    if (std::holds_alternative<long long>(value)) {
        if (type != Type::integer) {
            throw std::invalid_argument(error_message);
        }
    }

    if (std::holds_alternative<std::string>(value)) {
        if (type != Type::identifier && type != Type::type) {
            throw std::invalid_argument(error_message);
        }
    }

    this->value = value;
}

std::string Node::as_string(bool color, unsigned int depth) const {
    std::string result = "(";

    switch (this->type) {
        #define SERIALIZE_TYPE(X)    \
            case Type::X:            \
                result += #X;        \
                break

        SERIALIZE_TYPE(type);
        SERIALIZE_TYPE(identifier);
        SERIALIZE_TYPE(integer);
        SERIALIZE_TYPE(boolean);
        SERIALIZE_TYPE(massive);

        SERIALIZE_TYPE(cube);

        SERIALIZE_TYPE(logical_or);
        SERIALIZE_TYPE(logical_and);
        SERIALIZE_TYPE(equal);
        SERIALIZE_TYPE(not_equal);
        SERIALIZE_TYPE(more_than);
        SERIALIZE_TYPE(less_than);
        SERIALIZE_TYPE(addition);
        SERIALIZE_TYPE(subtraction);
        SERIALIZE_TYPE(multiplication);
        SERIALIZE_TYPE(division);
        SERIALIZE_TYPE(subscript);
        SERIALIZE_TYPE(typecheck);

        SERIALIZE_TYPE(negation);
        SERIALIZE_TYPE(logical_not);
        SERIALIZE_TYPE(size);
        SERIALIZE_TYPE(func_call);

        SERIALIZE_TYPE(arguments);

        SERIALIZE_TYPE(stmts);
        SERIALIZE_TYPE(var_decl);
        SERIALIZE_TYPE(func_decl);
        SERIALIZE_TYPE(assignment);
        SERIALIZE_TYPE(if_stmt);
        SERIALIZE_TYPE(loop_stmt);
        SERIALIZE_TYPE(while_stmt);
        SERIALIZE_TYPE(print);

        SERIALIZE_TYPE(control_sequence);
        SERIALIZE_TYPE(mfwd);
        SERIALIZE_TYPE(mbwd);
        SERIALIZE_TYPE(mlft);
        SERIALIZE_TYPE(mrgt);
        SERIALIZE_TYPE(lfwd);
        SERIALIZE_TYPE(lbwd);
        SERIALIZE_TYPE(llft);
        SERIALIZE_TYPE(lrgt);
        SERIALIZE_TYPE(stop);
        SERIALIZE_TYPE(chck);

        #undef SERIALIZE_TYPE

        default:
            result += "???";
    }

    if (this->type == Type::type) {
        if (color) result += "\x1b[32m";
        result += " " + std::get<std::string>(this->value);
        if (color) result += "\x1b[0m";
    }
    else if (this->type == Type::identifier) {
        if (color) result += "\x1b[33m";
        result += " \""
                + std::get<std::string>(this->value)
                + "\"";
        if (color) result += "\x1b[0m";
    }
    else if (this->type == Type::integer) {
        if (color) result += "\x1b[31m";
        result += " "
                + std::to_string(std::get<long long>(this->value));
        if (color) result += "\x1b[0m";
    }
    else if (this->type == Type::boolean) {
        if (color) result += "\x1b[31m";
        result += " ";
        result += std::get<bool>(this->value) ? "True" : "False";
        if (color) result += "\x1b[0m";
    }
    else {
        for (const auto& child_node : this->children) {
            result += "\n";
            for (unsigned int i = 0; i <= depth; i++) {
                result += "  ";
            }
            result += child_node->as_string(color, depth + 1);
        }
    }

    result += ")";

    return result;
}

}
