#pragma once
#include "expressions/Expression.h"

class NumberExpression: public Expression {
public:
    explicit NumberExpression(int value);
    std::shared_ptr<Type> eval() const override;
    void Accept(Visitor* visit) override;

    int value_;
};