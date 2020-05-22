//
// Created by bevertax on 02.04.2020.
//

#include "ExtensionList.h"
ExtensionList::ExtensionList() {}
ExtensionList::ExtensionList(std::string_view inherited_class): inherited_class_(inherited_class) {}
void ExtensionList::Accept(Visitor *visitor) { visitor->Visit(this); }
