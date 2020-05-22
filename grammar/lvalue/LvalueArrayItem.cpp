//
// Created by bevertax on 02.04.2020.
//

#include "LvalueArrayItem.h"


LvalueArrayItem::LvalueArrayItem(std::string_view identifier,
                                 Expression *expression): identifier_(identifier), expression_(expression) {}
void LvalueArrayItem::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
void LvalueArrayItem::Set(const std::shared_ptr<Type> &value) {}
