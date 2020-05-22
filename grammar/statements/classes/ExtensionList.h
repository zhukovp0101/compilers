#pragma once

#include <string_view>
#include <string>

#include <base_elements/BaseElement.h>

class ExtensionList: public BaseElement {
public:
  ExtensionList();
  ExtensionList(std::string_view inherited_class);
  void Accept(Visitor *visitor) override;
  std::string inherited_class_;
};

