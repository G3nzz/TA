#pragma once

#include <string>

#include "parser.hpp"
#include "ast.hpp"

#define YY_DECL yy::parser::symbol_type yylex(Driver& drv)
YY_DECL;

class Driver {
  public:
    Driver();

    int parse(const std::string& f);
    std::string file;
    std::unique_ptr<Cellbot::Node> result;

    void scan_begin();
    void scan_end();
    yy::location location;

    bool trace_parsing;
    bool trace_scanning;
};

