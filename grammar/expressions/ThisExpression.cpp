//
// Created by bevertax on 02.04.2020.
//

#include "ThisExpression.h"
ThisExpression::ThisExpression() {}
void ThisExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
