project(GrammarFunctionCalls)

set(PARSER_TARGET "Parser${PROJECT_NAME}")
set(SCANNER_TARGET "Scanner${PROJECT_NAME}")
set(TREE_TARGET "Tree${PROJECT_NAME}")

set(PARSER_OUTPUT "BISON_${PARSER_TARGET}_OUTPUTS")
set(SCANNER_OUTPUT "FLEX_${SCANNER_TARGET}_OUTPUTS")


set(
        HEADERS
        driver.hh
        parser.hh
)

BISON_TARGET(
        ${PARSER_TARGET}
        parser.y
        ${PROJECT_SOURCE_DIR}/parser.cpp
        COMPILE_FLAGS --graph
        DEFINES_FILE ${PROJECT_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        ${SCANNER_TARGET}
        scanner.l
        ${PROJECT_SOURCE_DIR}/scanner.cpp
)



ADD_FLEX_BISON_DEPENDENCY(${SCANNER_TARGET} ${PARSER_TARGET})

set(
        SOURCES
        ${${PARSER_OUTPUT}}
        ${${SCANNER_OUTPUT}}
        Program.cpp
	expressions/MathExpressions/NumberExpression.cpp
	expressions/MathExpressions/MulExpression.cpp
	expressions/MathExpressions/AddExpression.cpp
	expressions/MathExpressions/SubstractExpression.cpp
	expressions/MathExpressions/DivExpression.cpp
        expressions/IdentExpression.cpp
        statements/Statement.cpp
        statements/Assignment.cpp
	statements/PrintStatement.cpp
        statements/VarDecl.cpp
        statements/ScopeAssignmentList.cpp
	expressions/VarExpression.cpp expressions/VarExpression.h statements/classes/ClassDecl.cpp statements/classes/ClassDecl.h statements/classes/ExtensionList.cpp statements/classes/ExtensionList.h statements/List.cpp statements/List.h statements/Declaration.cpp statements/Declaration.h statements/methods/MethodDecl.cpp statements/methods/MethodDecl.h
	expressions/MathExpressions/EqExpression.cpp expressions/MathExpressions/EqExpression.h expressions/MathExpressions/FalseExpression.cpp expressions/MathExpressions/FalseExpression.h
	expressions/MathExpressions/AndExpression.cpp expressions/MathExpressions/AndExpression.h expressions/MathExpressions/TrueExpression.cpp expressions/MathExpressions/TrueExpression.h expressions/MathExpressions/LessExpression.cpp expressions/MathExpressions/LessExpression.h expressions/MathExpressions/MoreExpression.cpp expressions/MathExpressions/MoreExpression.h expressions/MathExpressions/ModExpression.cpp expressions/MathExpressions/ModExpression.h expressions/MathExpressions/NegativeExpression.cpp expressions/MathExpressions/NegativeExpression.h expressions/MathExpressions/OrExpression.cpp expressions/MathExpressions/OrExpression.h expressions/VarExpression.cpp expressions/VarExpression.h scope/Scope.cpp scope/Scope.h statements/Assert.cpp statements/Assert.h statements/IfElseStatement.cpp statements/IfElseStatement.h statements/WhileStatement.cpp statements/WhileStatement.h statements/ReturnStatement.cpp statements/ReturnStatement.h statements/methods/MethodInvocation.cpp statements/methods/MethodInvocation.h lvalue/IdentLvalue.cpp lvalue/IdentLvalue.h lvalue/LvalueArrayItem.cpp lvalue/LvalueArrayItem.h expressions/ExpressionArrayItem.cpp expressions/ExpressionArrayItem.h expressions/ArrayLength.cpp expressions/ArrayLength.h expressions/Array.cpp expressions/Array.h expressions/Variable.cpp expressions/Variable.h expressions/ThisExpression.cpp expressions/ThisExpression.h lvalue/Lvalue.cpp lvalue/Lvalue.h)

add_library(
        GrammarLib
        SHARED
        ${SOURCES}
)

#include_directories(${PROJECT_SOURCE_DIR}/../include)
target_include_directories(
        GrammarLib PRIVATE ${PROJECT_SOURCE_DIR}
)

target_include_directories(
        GrammarLib PRIVATE ${PROJECT_SOURCE_DIR}/..
)

target_include_directories(
        GrammarLib PRIVATE ${PROJECT_SOURCE_DIR}/../include
)