//
// Created by bevertax on 02.04.2020.
//

#include "ScopeDecl.h"
ScopeDecl::ScopeDecl(List<Statement> *statement_list): statement_list_(statement_list) {

}
void ScopeDecl::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
