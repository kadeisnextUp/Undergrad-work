#include <string>
#include "item.h"

Item::Item(const std::string &item_name): m_name(item_name) {}

std::string Item::getName() {
  return m_name;
}


bool Item::isEqual(Item other_item) {
	bool equal = false;
	if (m_name == other_item.getName()) {
		equal = true;
	}
  return equal;
}