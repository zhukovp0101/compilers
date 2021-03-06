#pragma once
#include "expressions/Expression.h"

class MoreExpression: public Expression {
 public:
    MoreExpression(Expression* e1, Expression* e2);
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};