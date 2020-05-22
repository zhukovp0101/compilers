#pragma once
#include "Expression.h"
#include <string_view>
#include <string>

class VarExpression: public Expression {
public:
  VarExpression(std::string_view type);
  void Accept(Visitor *visitor) override;
  std::shared_ptr<Type> eval() const override;
  std::string type_;
};

