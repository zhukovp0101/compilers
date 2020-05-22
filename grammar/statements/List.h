#pragma once

#include "Statement.h"
#include <vector>

template <class Item>
class List: public Statement {
public:
  void AddItem(Item* item) {
    items_.push_back(item);
  }
  void Accept(Visitor *visitor) override;

  std::vector<Item*> items_;
};
template <class Item> void List<Item>::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
