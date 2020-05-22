#pragma once

#include "BaseIncludes.h"
#include "Expression.h"
#include <include/visitors/Visitor.h>

class Variable: public Expression {
public:
  Variable(std::string_view type);
  void Accept(Visitor *visitor) override;
  std::shared_ptr<Type> eval() const override;
  std::string type_;
};

