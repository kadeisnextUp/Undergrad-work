#ifndef __BEADEDBAG_BEADEDBAG_HPP
#define __BEADEDBAG_BEADEDBAG_HPP

#include "item.h"
#include <vector>

class BeadedBag {
public:
  // Place your member function declarations here.
	/*
 * insert
 *
 * Adds a item to the beadedbag.
 *
 * input: A item variable that you want added to the bag.
 * output: none
 */
  void insert(Item to_insert);
  
  /*
 * size
 *
 * Return the number of items currently in the bag.
 *
 * input: none
 * output: A int that is the current amount of Items in the beadedbag.
 */
  int size();



  // Here's the declaration for contains, to get you started:
  /*
 * contains
 *
 * checks the beadedbag to see if a Item is already in there
 *
 * input: A Item variable that you want to check if it is already in the bag
 * output: A bool variable that is true if the Item is currrently in the bag and false if not
 */
  bool contains(Item maybe_contained_item);

private:
	std::vector<Item> bag;
};

#endif