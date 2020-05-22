//
// Created by bevertax on 02.04.2020.
//

#include "MethodDecl.h"
MethodDecl::MethodDecl(std::string_view type, std::string_view identifier,
                       List<VarDecl> *parameters, List<Statement> *statements): type_(type),
                       parameters_(parameters), statements_(statements) {
  identifier_ = identifier;
}
void MethodDecl::Accept(Visitor *visitor) { visitor->Visit(this); }
