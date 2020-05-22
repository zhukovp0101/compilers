#pragma once
#include "expressions/Expression.h"

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2);
    [[nodiscard]] std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* first;
    Expression* second;
};