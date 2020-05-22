//
// Created by bevertax on 02.04.2020.
//

#include "ExpressionArrayItem.h"
ExpressionArrayItem::ExpressionArrayItem(Expression *array, Expression *item): array_(array), item_(item) {}
void ExpressionArrayItem::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
