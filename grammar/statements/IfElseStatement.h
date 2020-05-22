#pragma once

#include <expressions/Expression.h>
class IfElseStatement: public Statement {
public:
  IfElseStatement(Expression* expression, Statement* if_statement, Statement* else_statement);
  void Accept(Visitor *visitor) override;

  Expression* expression_;
  Statement* if_statement_;
  Statement* else_statement_;
};

