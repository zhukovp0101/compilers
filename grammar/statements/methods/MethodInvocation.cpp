//
// Created by bevertax on 02.04.2020.
//

#include "MethodInvocation.h"
MethodInvocation::MethodInvocation(Expression *caller, std::string_view identifier,
                                   List<Expression> *arguments): caller_(caller), identifier_(identifier), arguments_(arguments) {}
void MethodInvocation::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
