// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 27 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"

    #include "driver.hpp"

#line 50 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"

  /// Build a parser object.
  parser::parser (Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_control: // control
      case symbol_kind::S_type_or_expr: // type_or_expr
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_opt_arguments: // opt_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_stmts: // stmts
        value.YY_MOVE_OR_COPY< AST_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_control_sequence: // control_sequence
      case symbol_kind::S_opt_elements: // opt_elements
      case symbol_kind::S_elements: // elements
        value.YY_MOVE_OR_COPY< std::vector<AST_TYPE> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_control: // control
      case symbol_kind::S_type_or_expr: // type_or_expr
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_opt_arguments: // opt_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_stmts: // stmts
        value.move< AST_TYPE > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_control_sequence: // control_sequence
      case symbol_kind::S_opt_elements: // opt_elements
      case symbol_kind::S_elements: // elements
        value.move< std::vector<AST_TYPE> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_control: // control
      case symbol_kind::S_type_or_expr: // type_or_expr
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_opt_arguments: // opt_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_stmts: // stmts
        value.copy< AST_TYPE > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_control_sequence: // control_sequence
      case symbol_kind::S_opt_elements: // opt_elements
      case symbol_kind::S_elements: // elements
        value.copy< std::vector<AST_TYPE> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_type: // type
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_control: // control
      case symbol_kind::S_type_or_expr: // type_or_expr
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_opt_arguments: // opt_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_stmts: // stmts
        value.move< AST_TYPE > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_control_sequence: // control_sequence
      case symbol_kind::S_opt_elements: // opt_elements
      case symbol_kind::S_elements: // elements
        value.move< std::vector<AST_TYPE> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_type: // type
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_integer: // integer
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_control: // control
      case symbol_kind::S_type_or_expr: // type_or_expr
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_opt_arguments: // opt_arguments
      case symbol_kind::S_arguments: // arguments
      case symbol_kind::S_stmts: // stmts
        yylhs.value.emplace< AST_TYPE > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_control_sequence: // control_sequence
      case symbol_kind::S_opt_elements: // opt_elements
      case symbol_kind::S_elements: // elements
        yylhs.value.emplace< std::vector<AST_TYPE> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: stmts
#line 89 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        {
    drv.result = std::move(yystack_[0].value.as < AST_TYPE > ());
}
#line 689 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 3: // type: "integer"
#line 95 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(type, "integer", yylhs.location); }
#line 695 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 4: // type: "boolean"
#line 96 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(type, "boolean", yylhs.location); }
#line 701 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 5: // type: "cube"
#line 97 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(type, "cube",    yylhs.location); }
#line 707 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 6: // type: "massive"
#line 98 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(type, "massive", yylhs.location); }
#line 713 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 7: // type: "void"
#line 99 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(type, "void",    yylhs.location); }
#line 719 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 8: // identifier: IDENT
#line 103 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        {
    yylhs.value.as < AST_TYPE > () = AST_MAKE_V(identifier, yystack_[0].value.as < std::string > (), yylhs.location);
}
#line 727 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 9: // integer: INT
#line 109 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
      {
    yylhs.value.as < AST_TYPE > () = AST_MAKE_V(integer, yystack_[0].value.as < long long > (), yylhs.location);
}
#line 735 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 10: // boolean: FALSE
#line 115 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(boolean, false, yylhs.location); }
#line 741 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 11: // boolean: TRUE
#line 116 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE_V(boolean, true,  yylhs.location); }
#line 747 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 12: // expr: identifier
#line 128 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
             { yylhs.value.as < AST_TYPE > () = std::move(yystack_[0].value.as < AST_TYPE > ()); }
#line 753 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 13: // expr: integer
#line 129 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
          { yylhs.value.as < AST_TYPE > () = std::move(yystack_[0].value.as < AST_TYPE > ()); }
#line 759 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 14: // expr: boolean
#line 130 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
          { yylhs.value.as < AST_TYPE > () = std::move(yystack_[0].value.as < AST_TYPE > ()); }
#line 765 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 15: // expr: expr "||" expr
#line 131 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                 {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(logical_or, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 776 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 16: // expr: expr "&&" expr
#line 137 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                 {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(logical_and, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 787 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 17: // expr: expr "==" expr
#line 143 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                 {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(equal, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 798 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 18: // expr: expr "~=" expr
#line 149 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                 {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(not_equal, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 809 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 19: // expr: expr ">" expr
#line 155 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(more_than, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 820 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 20: // expr: expr "<" expr
#line 161 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(less_than, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 831 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 21: // expr: expr "+" expr
#line 167 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(addition, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 842 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 22: // expr: expr "-" expr
#line 173 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(subtraction, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 853 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 23: // expr: expr "*" expr
#line 179 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(multiplication, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 864 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 24: // expr: expr "^" expr
#line 185 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(pow, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 875 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 25: // expr: expr "/" expr
#line 191 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(division, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 886 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 26: // expr: TYPECHECK "{" type_or_expr "," type_or_expr "}"
#line 197 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                                  {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(typecheck, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 897 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 27: // expr: "-" expr
#line 203 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                       {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(negation, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 906 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 28: // expr: "~" expr
#line 207 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                       {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(logical_not, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 915 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 29: // expr: SIZE expr
#line 211 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                        {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(size, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 924 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 30: // expr: expr "[" expr "]"
#line 215 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                    {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(subscript, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 935 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 31: // expr: identifier "(" opt_elements ")"
#line 221 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                  {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(func_call, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(yystack_[1].value.as < std::vector<AST_TYPE> > ().size() + 1);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));

    for (auto& element : yystack_[1].value.as < std::vector<AST_TYPE> > ()) {
        yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(element));
    }
}
#line 949 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 32: // expr: "{" opt_elements "}"
#line 230 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                       {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(massive, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children = std::move(yystack_[1].value.as < std::vector<AST_TYPE> > ());
}
#line 958 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 33: // expr: "{" control_sequence "}"
#line 234 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                           {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(control_sequence, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children = std::move(yystack_[1].value.as < std::vector<AST_TYPE> > ());
}
#line 967 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 34: // expr: "{" control_sequence ";" "}"
#line 238 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                               {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(control_sequence, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children = std::move(yystack_[2].value.as < std::vector<AST_TYPE> > ());
}
#line 976 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 35: // expr: "(" expr ")"
#line 242 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
               {
    yylhs.value.as < AST_TYPE > () = std::move(yystack_[1].value.as < AST_TYPE > ());
}
#line 984 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 36: // control_sequence: control
#line 248 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
          {
    yylhs.value.as < std::vector<AST_TYPE> > ().push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 992 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 37: // control_sequence: control_sequence ";" control
#line 251 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                               {
    yylhs.value.as < std::vector<AST_TYPE> > () = std::move(yystack_[2].value.as < std::vector<AST_TYPE> > ());
    yylhs.value.as < std::vector<AST_TYPE> > ().push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 1001 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 38: // control: "^_^"
#line 258 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(mfwd, yylhs.location); }
#line 1007 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 39: // control: "v_v"
#line 259 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(mbwd, yylhs.location); }
#line 1013 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 40: // control: "<_<"
#line 260 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(mlft, yylhs.location); }
#line 1019 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 41: // control: ">_>"
#line 261 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(mrgt, yylhs.location); }
#line 1025 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 42: // control: "^_0"
#line 262 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(lfwd, yylhs.location); }
#line 1031 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 43: // control: "v_0"
#line 263 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(lbwd, yylhs.location); }
#line 1037 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 44: // control: "<_0"
#line 264 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(llft, yylhs.location); }
#line 1043 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 45: // control: ">_0"
#line 265 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(lrgt, yylhs.location); }
#line 1049 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 46: // control: ">_<"
#line 266 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(stop, yylhs.location); }
#line 1055 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 47: // control: "*_*"
#line 267 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
        { yylhs.value.as < AST_TYPE > () = AST_MAKE(chck, yylhs.location); }
#line 1061 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 48: // type_or_expr: type
#line 271 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
       { yylhs.value.as < AST_TYPE > () = std::move(yystack_[0].value.as < AST_TYPE > ()); }
#line 1067 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 49: // type_or_expr: expr
#line 272 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
       { yylhs.value.as < AST_TYPE > () = std::move(yystack_[0].value.as < AST_TYPE > ()); }
#line 1073 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 50: // opt_elements: %empty
#line 276 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
               {}
#line 1079 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 51: // opt_elements: elements
#line 277 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
               { yylhs.value.as < std::vector<AST_TYPE> > () = std::move(yystack_[0].value.as < std::vector<AST_TYPE> > ()); }
#line 1085 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 52: // opt_elements: elements ","
#line 278 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
               { yylhs.value.as < std::vector<AST_TYPE> > () = std::move(yystack_[1].value.as < std::vector<AST_TYPE> > ()); }
#line 1091 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 53: // elements: expr
#line 282 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
       {
    yylhs.value.as < std::vector<AST_TYPE> > ().push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 1099 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 54: // elements: elements "," expr
#line 285 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                    {
    yylhs.value.as < std::vector<AST_TYPE> > () = std::move(yystack_[2].value.as < std::vector<AST_TYPE> > ());
    yylhs.value.as < std::vector<AST_TYPE> > ().push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 1108 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 55: // stmt: expr ";"
#line 292 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
              {
    yylhs.value.as < AST_TYPE > () = std::move(yystack_[1].value.as < AST_TYPE > ());
}
#line 1116 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 56: // stmt: type identifier "=" expr ";"
#line 295 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                  {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(var_decl, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(3);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[4].value.as < AST_TYPE > ())); // type
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ())); // name
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ())); // value
}
#line 1128 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 57: // stmt: type identifier ";"
#line 302 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                         {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(var_decl, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(3);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[2].value.as < AST_TYPE > ())); // type
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ())); // name
}
#line 1139 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 58: // stmt: expr "=" expr ";"
#line 308 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                       {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(assignment, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1150 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 59: // stmt: type FUNCTION identifier "(" opt_arguments ")" "{" stmts "}"
#line 314 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                                               {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(func_decl, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(4);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[8].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[6].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[4].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1163 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 60: // stmt: IF expr "{" stmts "}"
#line 322 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                        {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(if_stmt, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1174 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 61: // stmt: IF expr "{" stmts "}" ELSE "{" stmts "}"
#line 328 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                           {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(if_stmt, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(3);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[7].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[5].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1186 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 62: // stmt: LOOP identifier "=" expr ":" expr "{" stmts "}"
#line 335 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                                  {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(loop_stmt, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(4);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[7].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[5].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1199 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 63: // stmt: WHILE expr "{" stmts "}"
#line 343 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                           {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(while_stmt, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.reserve(2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[3].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1210 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 64: // stmt: PRINT expr ";"
#line 349 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                    {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(print, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
}
#line 1219 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 65: // opt_arguments: %empty
#line 356 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = AST_MAKE(arguments, yylhs.location); }
#line 1225 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 66: // opt_arguments: arguments
#line 357 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
            { yylhs.value.as < AST_TYPE > () = std::move(yystack_[0].value.as < AST_TYPE > ());           }
#line 1231 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 67: // arguments: type identifier
#line 361 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                  {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(arguments, yylhs.location);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 1241 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 68: // arguments: arguments "," type identifier
#line 366 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
                                {
    yylhs.value.as < AST_TYPE > () = std::move(yystack_[3].value.as < AST_TYPE > ());
    yylhs.value.as < AST_TYPE > ()->children.reserve(yylhs.value.as < AST_TYPE > ()->children.size() + 2);
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[1].value.as < AST_TYPE > ()));
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 1252 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 69: // stmts: %empty
#line 375 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
         {
    yylhs.value.as < AST_TYPE > () = AST_MAKE(stmts, yylhs.location);
}
#line 1260 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;

  case 70: // stmts: stmts stmt
#line 378 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"
             {
    yylhs.value.as < AST_TYPE > () = std::move(yystack_[1].value.as < AST_TYPE > ());
    yylhs.value.as < AST_TYPE > ()->children.push_back(std::move(yystack_[0].value.as < AST_TYPE > ()));
}
#line 1269 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"
    break;


#line 1273 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "TRUE", "FALSE", "IF", "ELSE",
  "TYPECHECK", "SIZE", "LOOP", "WHILE", "PRINT", "FUNCTION", "integer",
  "boolean", "cube", "massive", "void", "=", "==", "~=", "=>", "-", "+",
  "*", "^", "/", "~", "&&", "||", "<", ">", "(", ")", "[", "]", "{", "}",
  ":", ";", ",", "^_^", "v_v", "<_<", ">_>", "^_0", "v_0", "<_0", ">_0",
  ">_<", "*_*", "IDENT", "INT", "UNARY", "$accept", "program", "type",
  "identifier", "integer", "boolean", "expr", "control_sequence",
  "control", "type_or_expr", "opt_elements", "elements", "stmt",
  "opt_arguments", "arguments", "stmts", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -52;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -52,     3,   380,   -52,   -52,   -52,   432,   -11,   432,   -44,
     432,   432,   -52,   -52,   -52,   -52,   -52,   432,   432,   432,
      80,   -52,   -52,   -10,    -5,   -52,   -52,   447,   -52,   539,
     406,    -4,    11,   557,   468,    -4,    -4,   610,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   626,   -16,
     -52,     2,    -7,   -44,   -13,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   -52,
     -52,   -52,   626,     0,   432,   -52,   -52,   -52,   -52,   127,
     -52,   432,    13,   432,   -52,    19,   486,   196,   196,   -14,
     -14,   -12,    -4,   -12,    12,    12,    67,    67,   593,   130,
     406,   522,   180,   -52,   -52,   626,    34,   504,   -52,   -52,
     -52,    61,    31,   432,   -52,   -44,    36,    30,   -52,    37,
     -52,   575,   -52,    42,    34,   -52,   -52,   -52,   -44,   230,
     280,   330,   -52,   -52,   -52,   -52
  };

  const signed char
  parser::yydefact_[] =
  {
      69,     0,     2,     1,    11,    10,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     0,     0,     0,
      50,     8,     9,     0,    12,    13,    14,     0,    70,     0,
       0,    29,     0,     0,     0,    27,    28,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    53,     0,
      36,     0,    51,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      69,    48,    49,     0,     0,    69,    64,    35,    33,     0,
      32,    52,     0,     0,    57,     0,     0,    17,    18,    22,
      21,    23,    24,    25,    16,    15,    20,    19,     0,     0,
       0,     0,     0,    34,    37,    54,    65,     0,    31,    58,
      30,    60,     0,     0,    63,     0,     0,    66,    56,     0,
      26,     0,    67,     0,     0,    69,    69,    69,     0,     0,
       0,     0,    68,    61,    62,    59
  };

  const signed char
  parser::yypgoto_[] =
  {
     -52,   -52,   -29,    -9,   -52,   -52,    -2,   -52,     1,   -18,
      39,   -52,   -52,   -52,   -52,   -51
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,    23,    24,    25,    26,    27,    49,    50,    73,
      51,    52,    28,   116,   117,     2
  };

  const unsigned char
  parser::yytable_[] =
  {
      32,    71,    53,     3,    29,    83,    31,    21,    33,    34,
      61,    62,    63,    62,    54,    35,    36,    37,    48,    99,
      68,    78,    68,    79,   102,    30,    84,    55,    72,    74,
      68,    57,    58,    81,    59,    60,    61,    62,    63,    80,
     100,    21,    66,    67,    82,   106,    68,    12,    13,    14,
      15,    16,   108,    48,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   119,   120,   123,
     124,    71,   101,   125,   129,   130,   131,   115,   127,   105,
     104,   107,   112,     4,     5,     0,     0,     7,     8,    59,
      60,    61,    62,    63,    85,   128,     0,     0,    72,     0,
       0,    68,    17,     0,     0,     0,   122,    18,     0,     0,
       0,   121,    19,     0,     0,     0,    20,     0,     0,   132,
       0,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    21,    22,     4,     5,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,   103,     0,    20,   111,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,     0,
       0,    21,    22,     4,     5,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,     0,     0,    20,   114,    59,    60,
      61,    62,    63,     0,     0,     0,    66,    67,     0,     0,
      68,    21,    22,     4,     5,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,     0,     0,    20,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     4,     5,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,     0,     0,    20,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     4,     5,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,     0,     0,    20,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     4,     5,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,     0,     4,
       5,     0,    19,     7,     8,     0,    20,     0,     0,    12,
      13,    14,    15,    16,     0,     0,     0,     0,    17,     0,
       0,    21,    22,    18,     0,     4,     5,     0,    19,     7,
       8,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,    21,    22,    18,
       0,     0,     0,     0,    19,    56,    57,    58,    20,    59,
      60,    61,    62,    63,     0,    64,    65,    66,    67,     0,
       0,    68,     0,    21,    22,     0,    69,    57,    58,     0,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,     0,     0,    57,    58,    76,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68,     0,     0,    57,    58,   109,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,     0,
       0,    57,    58,   118,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,    68,     0,    57,    58,
     113,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,     0,     0,    68,     0,    70,    57,    58,     0,    59,
      60,    61,    62,    63,     0,    64,    65,    66,    67,     0,
       0,    68,     0,    75,    57,    58,     0,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,     0,     0,    68,
       0,   126,    57,    58,     0,    59,    60,    61,    62,    63,
       0,    64,    65,    66,    67,     0,     0,    68,   110,    57,
      58,     0,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,    77,    68,    57,    58,     0,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68
  };

  const short
  parser::yycheck_[] =
  {
       9,    30,    12,     0,     6,    18,     8,    51,    10,    11,
      24,    25,    26,    25,    23,    17,    18,    19,    20,    70,
      34,    37,    34,    39,    75,    36,    39,    32,    30,    18,
      34,    19,    20,    40,    22,    23,    24,    25,    26,    37,
      40,    51,    30,    31,    53,    32,    34,    13,    14,    15,
      16,    17,    33,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     6,    37,    33,
      40,   100,    74,    36,   125,   126,   127,   106,    36,    81,
      79,    83,   100,     3,     4,    -1,    -1,     7,     8,    22,
      23,    24,    25,    26,    55,   124,    -1,    -1,   100,    -1,
      -1,    34,    22,    -1,    -1,    -1,   115,    27,    -1,    -1,
      -1,   113,    32,    -1,    -1,    -1,    36,    -1,    -1,   128,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    -1,    37,    -1,    36,    37,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    51,    52,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    51,    52,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,     3,
       4,    -1,    32,     7,     8,    -1,    36,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    51,    52,    27,    -1,     3,     4,    -1,    32,     7,
       8,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    51,    52,    27,
      -1,    -1,    -1,    -1,    32,    18,    19,    20,    36,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    34,    -1,    51,    52,    -1,    39,    19,    20,    -1,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      -1,    -1,    34,    -1,    -1,    19,    20,    39,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    19,    20,    39,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    19,    20,    39,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    -1,    -1,    34,    -1,    19,    20,
      38,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    -1,    -1,    34,    -1,    36,    19,    20,    -1,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    34,    -1,    36,    19,    20,    -1,    22,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    -1,    -1,    34,
      -1,    36,    19,    20,    -1,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    35,    19,
      20,    -1,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    -1,    33,    34,    19,    20,    -1,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      34
  };

  const signed char
  parser::yystos_[] =
  {
       0,    55,    69,     0,     3,     4,     5,     7,     8,     9,
      10,    11,    13,    14,    15,    16,    17,    22,    27,    32,
      36,    51,    52,    56,    57,    58,    59,    60,    66,    60,
      36,    60,    57,    60,    60,    60,    60,    60,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    60,    61,
      62,    64,    65,    12,    57,    32,    18,    19,    20,    22,
      23,    24,    25,    26,    28,    29,    30,    31,    34,    39,
      36,    56,    60,    63,    18,    36,    39,    33,    37,    39,
      37,    40,    57,    18,    39,    64,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    69,
      40,    60,    69,    37,    62,    60,    32,    60,    33,    39,
      35,    37,    63,    38,    37,    56,    67,    68,    39,     6,
      37,    60,    57,    33,    40,    36,    36,    36,    56,    69,
      69,    69,    57,    37,    37,    37
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    54,    55,    56,    56,    56,    56,    56,    57,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     2,     2,     2,
       4,     4,     3,     3,     4,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     1,     3,     2,     5,     3,     4,     9,
       5,     9,     9,     5,     3,     0,     1,     2,     4,     0,
       2
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    89,    89,    95,    96,    97,    98,    99,   103,   109,
     115,   116,   128,   129,   130,   131,   137,   143,   149,   155,
     161,   167,   173,   179,   185,   191,   197,   203,   207,   211,
     215,   221,   230,   234,   238,   242,   248,   251,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   271,   272,
     276,   277,   278,   282,   285,   292,   295,   302,   308,   314,
     322,   328,   335,   343,   349,   356,   357,   361,   366,   375,
     378
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2025 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/build/generated/parser.cpp"

#line 383 "/mnt/c/Users/soul8/Theory Automata/Lab3/rev1/src/parser.y"


void yy::parser::error(const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
    exit(1);
}

