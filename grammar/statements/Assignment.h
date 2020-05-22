#pragma once

#include "expressions/Expression.h"
#include "Statement.h"
#include "../lvalue/Lvalue.h"

#include <string>

class Assignment: public Statement {
 public:
    Assignment(Lvalue* lvalue, Expression* expression);
    void Accept(Visitor* visitor);

    Lvalue* variable_;
    Expression* expression_;
};