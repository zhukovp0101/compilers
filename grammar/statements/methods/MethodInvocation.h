#pragma once

#include <expressions/Expression.h>
#include "BaseIncludes.h"
#include "../List.h"

class MethodInvocation: public Expression {
public:
  MethodInvocation(Expression* caller, std::string_view identifier, List<Expression>* arguments);
  void Accept(Visitor *visitor) override;
  std::shared_ptr<Type> eval() const override {};

  Expression* caller_;
  std::string identifier_;
  List<Expression>* arguments_;
};

