//
// Created by bevertax on 02.04.2020.
//

#include "WhileStatement.h"
WhileStatement::WhileStatement(Expression *expression, Statement *statement): expression_(expression), statement_(statement) {}
void WhileStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
