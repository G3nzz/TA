#pragma once

#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "location.hh"

namespace Cellbot {

class Node {
  public:
    enum class Type {
        type, identifier, integer, boolean, massive,

        // runtime only
        cube,

        logical_or, logical_and, equal, not_equal,
        more_than, less_than, addition, subtraction,
        multiplication, pow, division, subscript,
        typecheck,

        negation, logical_not, size, func_call,

        arguments,

        stmts, var_decl, func_decl, assignment,
        massive_assignment, if_stmt, loop_stmt,
        while_stmt, print,

        control_sequence,
        mfwd, mbwd, mlft, mrgt,
        lfwd, lbwd, llft, lrgt,
        stop, chck,
    } type;

    typedef std::variant<long long, std::string, bool> ValueTypes;
    ValueTypes value;

    std::vector<std::unique_ptr<Node>> children;

    yy::location location;

    Node(const Node& other);
    Node(Type type, yy::location loc);
    Node(Type type, ValueTypes value, yy::location loc);

    std::string as_string(bool color = false, unsigned int depth = 0) const;
};

}

