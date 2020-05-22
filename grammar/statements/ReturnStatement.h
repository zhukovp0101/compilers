#pragma once

#include <expressions/Expression.h>
class ReturnStatement: public Statement{
public:
  ReturnStatement(Expression* expression);
  void Accept(Visitor *visitor) override;

  Expression* expression_;
};

