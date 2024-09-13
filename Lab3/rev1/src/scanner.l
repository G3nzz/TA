%{
    #include <cerrno>
    #include <string>
    #include "driver.hpp"
    #include "parser.hpp"
%}

%option noyywrap batch debug

%{
    yy::parser::symbol_type
    make_NUMBER(const std::string &s, const yy::parser::location_type& loc);
%}

ws      [ \t]+
int     -?[0-9]+
ident   [a-zA-Z_][a-zA-Z0-9_]*

%{
    #define YY_USER_ACTION loc.columns(yyleng);
%}

%%

%{
    yy::location& loc = drv.location;
    loc.step();
%}

{ws}+           loc.step();
\n+             loc.lines(yyleng); loc.step();

"//"            {
    int c;

    while((c = yyinput()) != 0) {
        if (c == '\n') {
            unput(c);
            break;
        }
    }
}

"="             return yy::parser::make_EQUAL(loc);
"=="            return yy::parser::make_DEQUAL(loc);
"~="            return yy::parser::make_NEQUAL(loc);
"=>"            return yy::parser::make_ACCESS(loc);
"-"             return yy::parser::make_MINUS(loc);
"+"             return yy::parser::make_PLUS(loc);
"*"             return yy::parser::make_STAR(loc);
"^"             return yy::parser::make_POW(loc);
"/"             return yy::parser::make_SLASH(loc);
"~"             return yy::parser::make_TILDE(loc);
"&&"            return yy::parser::make_AND(loc);
"||"            return yy::parser::make_OR(loc);
"<"             return yy::parser::make_LESS(loc);
">"             return yy::parser::make_MORE(loc);
"("             return yy::parser::make_LPAREN(loc);
")"             return yy::parser::make_RPAREN(loc);
"["             return yy::parser::make_LBRACK(loc);
"]"             return yy::parser::make_RBRACK(loc);
"{"             return yy::parser::make_LBRACE(loc);
"}"             return yy::parser::make_RBRACE(loc);
":"             return yy::parser::make_COLON(loc);
";"             return yy::parser::make_SCOLON(loc);
","             return yy::parser::make_COMMA(loc);

"^_^"           return yy::parser::make_MFWD(loc);
"v_v"           return yy::parser::make_MBWD(loc);
"<_<"           return yy::parser::make_MLFT(loc);
">_>"           return yy::parser::make_MRGT(loc);
"^_0"           return yy::parser::make_LFWD(loc);
"v_0"           return yy::parser::make_LBWD(loc);
"<_0"           return yy::parser::make_LLFT(loc);
">_0"           return yy::parser::make_LRGT(loc);
">_<"           return yy::parser::make_STOP(loc);
"*_*"           return yy::parser::make_CHCK(loc);

"true"          return yy::parser::make_TRUE(loc);
"false"         return yy::parser::make_FALSE(loc);
"if"            return yy::parser::make_IF(loc);
"else"          return yy::parser::make_ELSE(loc);
"type_check"    return yy::parser::make_TYPECHECK(loc);
"size"          return yy::parser::make_SIZE(loc);
"loop"          return yy::parser::make_LOOP(loc);
"while"         return yy::parser::make_WHILE(loc);
"print"         return yy::parser::make_PRINT(loc);
"function"      return yy::parser::make_FUNCTION(loc);

"integer"       return yy::parser::make_TYPE_INTEGER(loc);
"boolean"       return yy::parser::make_TYPE_BOOLEAN(loc);
"cube"          return yy::parser::make_TYPE_CUBE(loc);
"massive"       return yy::parser::make_TYPE_MASSIVE(loc);
"void"          return yy::parser::make_TYPE_VOID(loc);

{ident}         return yy::parser::make_IDENT(yytext, loc);
{int}           return yy::parser::make_INT(std::stoll(yytext), loc);

<<EOF>>         return yy::parser::make_YYEOF(loc);

.               {
    std::cout << loc << ": unrecognized character: " << yytext << "\n";
    exit(1);
}

%%

void Driver::scan_begin() {
    yy_flex_debug = trace_scanning;
    if (file.empty() || file == "-") {
        yyin = stdin;
    }
    else if (!(yyin = fopen(file.c_str(), "r"))) {
        std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
        exit(EXIT_FAILURE);
    }
}

void Driver::scan_end() {
    fclose(yyin);
}

