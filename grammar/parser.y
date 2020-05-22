%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
    class Expression;
    class ClassDecl;
    class Declaration;
    template<class T>
    class List;
    class ExtensionList;
    class Statement;
    class VarDecl;
    class Lvalue;
    class MethodDecl;
    class NumberExpression;
    class AddExpression;
    class SubstractExpression;
    class DivExpression;
    class IdentExpression;
    class Assignment;
    class AssignmentList;

    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "expressions/MathExpressions/AddExpression.h"
    #include "expressions/MathExpressions/AndExpression.h"
    #include "expressions/MathExpressions/DivExpression.h"
    #include "expressions/MathExpressions/EqExpression.h"
    #include "expressions/MathExpressions/FalseExpression.h"
    #include "expressions/MathExpressions/LessExpression.h"
    #include "expressions/MathExpressions/ModExpression.h"
    #include "expressions/MathExpressions/MoreExpression.h"
    #include "expressions/MathExpressions/MulExpression.h"
    #include "expressions/MathExpressions/NegativeExpression.h"
    #include "expressions/MathExpressions/NumberExpression.h"
    #include "expressions/MathExpressions/OrExpression.h"
    #include "expressions/MathExpressions/SubstractExpression.h"
    #include "expressions/MathExpressions/TrueExpression.h"
    #include "expressions/Array.h"
    #include "expressions/ArrayLength.h"
    #include "expressions/Expression.h"
    #include "expressions/ExpressionArrayItem.h"
    #include "expressions/IdentExpression.h"
    #include "expressions/ThisExpression.h"
    #include "expressions/VarExpression.h"
    #include "expressions/Variable.h"
    #include "statements/ScopeDecl.h"
    #include "statements/Assignment.h"
    #include "lvalue/IdentLvalue.h"
    #include "statements/classes/ClassDecl.h"
    #include "statements/PrintStatement.h"
    #include "statements/VarDecl.h"
    #include "lvalue/LvalueArrayItem.h"
    #include "statements/Statement.h"
    #include "statements/List.h"
    #include "statements/Declaration.h"
    #include "statements/ReturnStatement.h"
    #include "statements/methods/MethodInvocation.h"
    #include "statements/Assert.h"
    #include "statements/methods/MethodDecl.h"
    #include "statements/classes/ExtensionList.h"
    #include "statements/ScopeAssignmentList.h"
    #include "statements/WhileStatement.h"
    #include "statements/IfElseStatement.h"
    #include "statements/FunctionCallStatement.h"
    #include "../types/Type.h"
    #include "Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN "="

    LPAREN "("
    RPAREN ")"
    LBRACE "{"
    RBRACE "}"
    LSQUAREBRACKET "["
    RSQUAREBRACKET "]"

    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    PERCENT "%"

    TRUE "true"
    FALSE "false"
    AND "&&"
    OR "||"
    LESS "<"
    MORE ">"
    EQ "=="
    NEG "!"

    CLASS "class"
    PUBLIC "public"
    STATIC "static"
    MAIN "main"
    VOID "void"

    NEW "new"
    THIS "this"
    RETURN "return"
    ASSERT "assert"
    EXTENDS "extends"
    PRINTLN "System.out.println"
    LENGTH "length"

    COMMA ","
    DOT "."
    SEMICOLON ";"

    IF "if"
    ELSE "else"
    WHILE "while"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <Program*> unit
%nterm <Program*> program

%nterm <ClassDecl*> main_class
%nterm <ClassDecl*> class_declaration;
%nterm <List<ClassDecl>*> class_declaration_list
%nterm <ExtensionList*> extension_list

%nterm <List<Declaration>*> declaration_list
%nterm <Declaration*> declaration

%nterm <std::string> type
%nterm <std::string> simple_type
%nterm <std::string> array_type
%nterm <std::string> type_identifier

%nterm <MethodDecl*> method_declaration
%nterm <List<VarDecl>*> signature_parameter_list
%nterm <List<VarDecl>*> empty_signature_parameter_list
%nterm <List<VarDecl>*> complex_signature_parameter_list
%nterm <VarDecl*> signature_parameter

%nterm <List<Statement>*> statement_list
%nterm <Statement*> statement
%nterm <Expression*> expr

%nterm <VarDecl*> local_variable_declaration
%nterm <VarDecl*> variable_declaration

%nterm <Expression*> method_invocation
%nterm <List<Expression>*> call_parameter_list
%nterm <List<Expression>*> empty_call_parameter_list
%nterm <List<Expression>*> complex_call_parameter_list
%nterm <Expression*> call_parameter

%nterm <Lvalue*> lvalue



// %printer { yyo << $$; } <*>;

%%
%start unit;

unit: program { $$ = $1; driver.program = $1; };

program: main_class class_declaration_list { $2->AddItem($1); $$ = new Program($2); };

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statement_list "}" "}" { auto list_declaration = new List<Declaration>(); list_declaration->AddItem(new MethodDecl("void", "main", new List<VarDecl>(), $11)); $$ = new ClassDecl($2, new ExtensionList(), list_declaration); };

class_declaration_list: %empty { $$ = new List<ClassDecl>(); } | class_declaration_list class_declaration { $1->AddItem($2); $$ = $1; };
class_declaration: "class" "identifier" extension_list "{" declaration_list "}" { $$ = new ClassDecl($2, $3, $5); };
extension_list: %empty { $$ = new ExtensionList(); } | "extends" "identifier" { $$ = new ExtensionList($2); };

declaration_list: %empty { $$ = new List<Declaration>(); } | declaration_list declaration { $1->AddItem($2); $$ = $1; };
declaration: variable_declaration { $$ = $1; } | method_declaration { $$ = $1; };

method_declaration: "public" type "identifier" "(" signature_parameter_list ")" "{" statement_list "}" { $$ = new MethodDecl($2, $3, $5, $8); };
signature_parameter_list: empty_signature_parameter_list { $$ = $1; } | complex_signature_parameter_list { $$ = $1; };
empty_signature_parameter_list: %empty { $$ = new List<VarDecl>(); } ;
complex_signature_parameter_list: signature_parameter { $$ = new List<VarDecl>(); $$->AddItem($1); } |
                                  complex_signature_parameter_list "," signature_parameter { $1->AddItem($3); $$ = $1; };
signature_parameter: type "identifier" { $$ = new VarDecl($1, $2); };

type: simple_type { $$ = $1; } | array_type { $$ = $1; };
simple_type: type_identifier { $$ = $1; };
type_identifier: "identifier" { $$ = $1; };
array_type: simple_type "[" "]" { $$ = $1 + '[' + ']'; };

statement_list: %empty { $$ = new List<Statement>(); }| statement_list statement { $1->AddItem($2); $$ = $1;};
statement:	"assert" "(" expr ")" ";" { $$ = new Assert($3); } |
                local_variable_declaration { $$ = $1; } |
                "{" statement_list "}" { $$ = new ScopeDecl($2); } |
                "if"  "(" expr ")" statement { $$ = new IfElseStatement($3, $5, nullptr); }|
                "if" "(" expr ")" statement "else" statement { $$ = new IfElseStatement($3, $5, $7); }|
                "while" "(" expr ")" statement {$$ = new WhileStatement($3, $5); }|
                "System.out.println" "(" expr ")" ";" { $$ = new PrintStatement($3); } |
                lvalue "=" expr ";" { $$ = new Assignment($1, $3); } |
                "return" expr ";" { $$ = new ReturnStatement($2); } |
                method_invocation ";" { $$ = $1; };

local_variable_declaration: variable_declaration { $$ = $1; };
variable_declaration: type "identifier" ";" { $$ = new VarDecl($1, $2); };

method_invocation: expr "." "identifier" "(" call_parameter_list ")" { $$ = new MethodInvocation($1, $3, $5); };
call_parameter_list: empty_call_parameter_list { $$ = $1; } | complex_call_parameter_list { $$ = $1; };
empty_call_parameter_list: %empty { $$ = new List<Expression>(); } ;
complex_call_parameter_list: call_parameter { $$ = new List<Expression>(); $$->AddItem($1); } |
                                  complex_call_parameter_list "," call_parameter { $1->AddItem($3); $$ = $1; };
call_parameter: expr { $$ = $1; };

lvalue:	"identifier" { $$ = new IdentLvalue($1); } | "identifier" "[" expr "]" { $$ = new LvalueArrayItem($1, $3); };

%left "+" "-";
%left "*" "/";

expr:       expr "&&" expr { $$ = new AndExpression($1, $3); } |
            expr "||" expr { $$ = new OrExpression($1, $3); } |
            expr "<" expr { $$ = new LessExpression($1, $3); } |
            expr ">" expr { $$ = new MoreExpression($1, $3); } |
            expr "==" expr { $$ = new EqExpression($1, $3); } |
            expr "+" expr { $$ = new AddExpression($1, $3); } |
            expr "-" expr { $$ = new SubstractExpression($1, $3); } |
            expr "*" expr { $$ = new MulExpression($1, $3); } |
            expr "/" expr { $$ = new DivExpression($1, $3); } |
            expr "%" expr { $$ = new ModExpression($1, $3); } |
            expr "[" expr "]" { $$ = new ExpressionArrayItem($1, $3); } |
            expr "." "length" { $$ = new ArrayLength($1); } |
            "new" simple_type "[" expr "]" { $$ = new Array($2, $4); }|
            "new" type_identifier "(" ")" { $$ = new Variable($2); }|
            "!" expr { $$ = new NegativeExpression($2); } |
            "(" expr ")" { $$ = $2; }|
            "identifier" {$$ = new IdentExpression($1); } |
            "number" { $$ = new NumberExpression($1); } |
            "this" { $$ = new ThisExpression(); }|
            "true" { $$ = new TrueExpression(); } |
            "false" { $$ = new FalseExpression(); } |
            method_invocation { $$ = $1; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
