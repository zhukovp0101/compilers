//
// Created by bevertax on 02.04.2020.
//

#include "IfElseStatement.h"
IfElseStatement::IfElseStatement(Expression *expression,
                                 Statement *if_statement,
                                 Statement *else_statement): expression_(expression), if_statement_(if_statement), else_statement_(else_statement) {

                                 }
void IfElseStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
