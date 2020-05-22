#pragma once
#include "grammar/expressions/Expression.h"

class NegativeExpression: public Expression {
 public:
    NegativeExpression(Expression* expression);
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* expression;
};