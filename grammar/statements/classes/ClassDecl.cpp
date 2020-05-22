//
// Created by bevertax on 02.04.2020.
//

#include "ClassDecl.h"

ClassDecl::ClassDecl(std::string_view name, ExtensionList *extension_list,
             List<Declaration> *declaration_list): name_(name), extension_list_(extension_list), declaration_list_(declaration_list) {}
void ClassDecl::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
