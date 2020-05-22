#pragma once
#include "Expression.h"

#include <string>
#include <string_view>

class IdentExpression: public Expression {
 public:
    explicit IdentExpression(std::string_view identifier);
    [[nodiscard]] std::shared_ptr<Type> eval() const override;
    void Accept(Visitor *visitor) override;
    std::string identifier_;
};