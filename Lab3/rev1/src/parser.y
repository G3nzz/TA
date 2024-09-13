%skeleton "lalr1.cc"
%require "3.8"

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include "ast.hpp"
    #define AST_TYPE std::unique_ptr<Cellbot::Node>
    #define AST_MAKE(X, Y) std::make_unique<Cellbot::Node>(Cellbot::Node::Type::X, Y)
    #define AST_MAKE_V(X, Y, Z) std::make_unique<Cellbot::Node>(Cellbot::Node::Type::X, Y, Z)
    class Driver;
}

%param { Driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
    #include "driver.hpp"
}

%define api.token.prefix {TOK_}
%token TRUE
       FALSE
       IF
       ELSE
       TYPECHECK
       SIZE
       LOOP
       WHILE
       PRINT
       FUNCTION
       TYPE_INTEGER "integer"
       TYPE_BOOLEAN "boolean"
       TYPE_CUBE    "cube"
       TYPE_MASSIVE "massive"
       TYPE_VOID    "void"
       EQUAL   "="
       DEQUAL  "=="
       NEQUAL  "~="
       ACCESS  "=>"
       MINUS   "-"
       PLUS    "+"
       STAR    "*"
       POW     "^"
       SLASH   "/"
       TILDE   "~"
       AND     "&&"
       OR      "||"
       LESS    "<"
       MORE    ">"
       LPAREN  "("
       RPAREN  ")"
       LBRACK  "["
       RBRACK  "]"
       LBRACE  "{"
       RBRACE  "}"
       COLON   ":"
       SCOLON  ";"
       COMMA   ","
       MFWD    "^_^"
       MBWD    "v_v"
       MLFT    "<_<"
       MRGT    ">_>"
       LFWD    "^_0"
       LBWD    "v_0"
       LLFT    "<_0"
       LRGT    ">_0"
       STOP    ">_<"
       CHCK    "*_*";

%token <std::string> IDENT
%token <long long> INT

%%

%start program;

program:
  stmts {
    drv.result = std::move($1);
};

%nterm <AST_TYPE> type;
type:
  "integer" { $$ = AST_MAKE_V(type, "integer", @$); }
| "boolean" { $$ = AST_MAKE_V(type, "boolean", @$); }
| "cube"    { $$ = AST_MAKE_V(type, "cube",    @$); }
| "massive" { $$ = AST_MAKE_V(type, "massive", @$); }
| "void"    { $$ = AST_MAKE_V(type, "void",    @$); };

%nterm <AST_TYPE> identifier;
identifier:
  IDENT {
    $$ = AST_MAKE_V(identifier, $1, @$);
};

%nterm <AST_TYPE> integer;
integer:
  INT {
    $$ = AST_MAKE_V(integer, $1, @$);
};

%nterm <AST_TYPE> boolean;
boolean:
  FALSE { $$ = AST_MAKE_V(boolean, false, @$); }
| TRUE  { $$ = AST_MAKE_V(boolean, true,  @$); };

%left "||" "&&";
%left "==" "~=";
%left ">" "<";
%left "+" "-";
%left "*" "/";
%left "^";
%precedence UNARY;
%left "[";
%nterm <AST_TYPE> expr;
expr:
  identifier { $$ = std::move($1); }
| integer { $$ = std::move($1); }
| boolean { $$ = std::move($1); }
| expr "||" expr {
    $$ = AST_MAKE(logical_or, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "&&" expr {
    $$ = AST_MAKE(logical_and, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "==" expr {
    $$ = AST_MAKE(equal, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "~=" expr {
    $$ = AST_MAKE(not_equal, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr ">" expr {
    $$ = AST_MAKE(more_than, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "<" expr {
    $$ = AST_MAKE(less_than, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "+" expr {
    $$ = AST_MAKE(addition, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "-" expr {
    $$ = AST_MAKE(subtraction, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "*" expr {
    $$ = AST_MAKE(multiplication, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "^" expr {
    $$ = AST_MAKE(pow, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| expr "/" expr {
    $$ = AST_MAKE(division, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| TYPECHECK "{" type_or_expr "," type_or_expr "}" {
    $$ = AST_MAKE(typecheck, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($3));
    $$->children.push_back(std::move($5));
}
| "-" expr %prec UNARY {
    $$ = AST_MAKE(negation, @$);
    $$->children.push_back(std::move($2));
}
| "~" expr %prec UNARY {
    $$ = AST_MAKE(logical_not, @$);
    $$->children.push_back(std::move($2));
}
| SIZE expr %prec UNARY {
    $$ = AST_MAKE(size, @$);
    $$->children.push_back(std::move($2));
}
| expr "[" expr "]" {
    $$ = AST_MAKE(subscript, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| identifier "(" opt_elements ")" {
    $$ = AST_MAKE(func_call, @$);
    $$->children.reserve($3.size() + 1);
    $$->children.push_back(std::move($1));

    for (auto& element : $3) {
        $$->children.push_back(std::move(element));
    }
}
| "{" opt_elements "}" {
    $$ = AST_MAKE(massive, @$);
    $$->children = std::move($2);
}
| "{" control_sequence "}" {
    $$ = AST_MAKE(control_sequence, @$);
    $$->children = std::move($2);
}
| "{" control_sequence ";" "}" {
    $$ = AST_MAKE(control_sequence, @$);
    $$->children = std::move($2);
}
| "(" expr ")" {
    $$ = std::move($2);
};

%nterm <std::vector<AST_TYPE>> control_sequence;
control_sequence:
  control {
    $$.push_back(std::move($1));
}
| control_sequence ";" control {
    $$ = std::move($1);
    $$.push_back(std::move($3));
};

%nterm <AST_TYPE> control;
control:
  "^_^" { $$ = AST_MAKE(mfwd, @$); }
| "v_v" { $$ = AST_MAKE(mbwd, @$); }
| "<_<" { $$ = AST_MAKE(mlft, @$); }
| ">_>" { $$ = AST_MAKE(mrgt, @$); }
| "^_0" { $$ = AST_MAKE(lfwd, @$); }
| "v_0" { $$ = AST_MAKE(lbwd, @$); }
| "<_0" { $$ = AST_MAKE(llft, @$); }
| ">_0" { $$ = AST_MAKE(lrgt, @$); }
| ">_<" { $$ = AST_MAKE(stop, @$); }
| "*_*" { $$ = AST_MAKE(chck, @$); };

%nterm <AST_TYPE> type_or_expr;
type_or_expr:
  type { $$ = std::move($1); }
| expr { $$ = std::move($1); };

%nterm <std::vector<AST_TYPE>> opt_elements;
opt_elements:
  %empty       {}
| elements     { $$ = std::move($1); }
| elements "," { $$ = std::move($1); };

%nterm <std::vector<AST_TYPE>> elements;
elements:
  expr {
    $$.push_back(std::move($1));
}
| elements "," expr {
    $$ = std::move($1);
    $$.push_back(std::move($3));
};

%nterm <AST_TYPE> stmt;
stmt:
  expr SCOLON {
    $$ = std::move($1);
}
| type identifier "=" expr SCOLON {
    $$ = AST_MAKE(var_decl, @$);
    $$->children.reserve(3);
    $$->children.push_back(std::move($1)); // type
    $$->children.push_back(std::move($2)); // name
    $$->children.push_back(std::move($4)); // value
}
| type identifier SCOLON {
    $$ = AST_MAKE(var_decl, @$);
    $$->children.reserve(3);
    $$->children.push_back(std::move($1)); // type
    $$->children.push_back(std::move($2)); // name
}
| expr "=" expr SCOLON {
    $$ = AST_MAKE(assignment, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
}
| type FUNCTION identifier "(" opt_arguments ")" "{" stmts "}" {
    $$ = AST_MAKE(func_decl, @$);
    $$->children.reserve(4);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($3));
    $$->children.push_back(std::move($5));
    $$->children.push_back(std::move($8));
}
| IF expr "{" stmts "}" {
    $$ = AST_MAKE(if_stmt, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($2));
    $$->children.push_back(std::move($4));
}
| IF expr "{" stmts "}" ELSE "{" stmts "}" {
    $$ = AST_MAKE(if_stmt, @$);
    $$->children.reserve(3);
    $$->children.push_back(std::move($2));
    $$->children.push_back(std::move($4));
    $$->children.push_back(std::move($8));
}
| LOOP identifier "=" expr ":" expr "{" stmts "}" {
    $$ = AST_MAKE(loop_stmt, @$);
    $$->children.reserve(4);
    $$->children.push_back(std::move($2));
    $$->children.push_back(std::move($4));
    $$->children.push_back(std::move($6));
    $$->children.push_back(std::move($8));
}
| WHILE expr "{" stmts "}" {
    $$ = AST_MAKE(while_stmt, @$);
    $$->children.reserve(2);
    $$->children.push_back(std::move($2));
    $$->children.push_back(std::move($4));
}
| PRINT expr SCOLON {
    $$ = AST_MAKE(print, @$);
    $$->children.push_back(std::move($2));
};

%nterm <AST_TYPE> opt_arguments;
opt_arguments:
  %empty    { $$ = AST_MAKE(arguments, @$); }
| arguments { $$ = std::move($1);           };

%nterm <AST_TYPE> arguments;
arguments:
  type identifier {
    $$ = AST_MAKE(arguments, @$);
    $$->children.push_back(std::move($1));
    $$->children.push_back(std::move($2));
}
| arguments "," type identifier {
    $$ = std::move($1);
    $$->children.reserve($$->children.size() + 2);
    $$->children.push_back(std::move($3));
    $$->children.push_back(std::move($4));
};

%nterm <AST_TYPE> stmts;
stmts:
  %empty {
    $$ = AST_MAKE(stmts, @$);
}
| stmts stmt {
    $$ = std::move($1);
    $$->children.push_back(std::move($2));
};

%%

void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
    exit(1);
}

