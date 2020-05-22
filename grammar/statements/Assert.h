#pragma once

#include "BaseIncludes.h"
#include "Statement.h"
#include "expressions/Expression.h"

class Assert: public Statement {
public:
  Assert(Expression* expression);
  Expression* expression_;
  void Accept(Visitor *visitor) override;
};

