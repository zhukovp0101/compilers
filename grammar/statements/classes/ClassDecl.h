#pragma once

#include <base_elements/BaseElement.h>

#include "ExtensionList.h"
#include "../List.h"
#include "../Declaration.h"

#include <string>
#include <string_view>

class ClassDecl : public Statement {
public:
  ClassDecl(std::string_view name, ExtensionList *extension_list,
            List<Declaration> *declaration_list);
  void Accept(Visitor *visitor) override;
  std::string name_;
  ExtensionList *extension_list_;
  List<Declaration> *declaration_list_;
};
