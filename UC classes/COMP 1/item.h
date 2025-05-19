#ifndef __BEADEDBAG_ITEM_HPP
#define __BEADEDBAG_ITEM_HPP

#include <string>

class Item {
public:
  Item(const std::string &item_name);

  /*
 * getName
 *
 * Returns the name of a Item.
 *
 * input: none
 * output: A string that is the name of a Item.
 */
  std::string getName();

  /*
 * isequal
 *
 * Checks to see if two Items are the same.
 *
 * input: A Item variable that is the item you want to check.
 * output: A bool variable that is true if the two Items are the same and false otherwise.
 */
  bool isEqual(Item other);

private:
  std::string m_name;
};

#endif