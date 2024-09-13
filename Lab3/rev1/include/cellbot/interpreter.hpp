#pragma once

#include <forward_list>
#include <map>
#include <optional>

#include "location.hh"
#include "ast.hpp"
#include "simulation.hpp"

namespace Cellbot {

class Interpreter {
  public:
    Simulation sim;

    Interpreter(Simulation sim);

    std::optional<std::unique_ptr<Node>> evaluate(const Node& node);

  private:
    std::forward_list<std::pair<std::map<std::string, std::unique_ptr<Node>>,
                                bool>> environment;

    void enter_scope(bool function = false);

    std::optional<std::unique_ptr<Node>*> var_find(std::string name);

    void var_assign(std::string name, std::unique_ptr<Node> value);

    void exit_scope();

    std::unique_ptr<Node> to_boolean(std::unique_ptr<Node> node) const;

    std::unique_ptr<Node> to_integer(std::unique_ptr<Node> node) const;

    std::unique_ptr<Node> evaluate_and_get_boolean(const Node& node);

    std::unique_ptr<Node> evaluate_and_get_integer(const Node& node);

    std::unique_ptr<Node> evaluate_and_get_massive(const Node& node);

    void report(const yy::location& loc, std::string error_text) const;
};

}

