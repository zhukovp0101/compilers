//
// Created by bevertax on 02.04.2020.
//

#include "ReturnStatement.h"
ReturnStatement::ReturnStatement(Expression *expression): expression_(expression) {}
void ReturnStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
