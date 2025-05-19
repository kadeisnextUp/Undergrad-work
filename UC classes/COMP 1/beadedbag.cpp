#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// Implement the BeadedBag::size and BeadedBag::insert member functions here.
void BeadedBag::insert(Item to_insert) {
	if (!contains(to_insert)) {
		bag.push_back(to_insert);
	}
	
}
int BeadedBag::size() {
	return bag.size();

}


// Complete the implementation of the BeadedBag::contains member function.
bool BeadedBag::contains(Item maybe_contained_item) {
	bool contain = false;

	for (int x = 0; x < bag.size(); x++) {
		if (bag[x].getName() == maybe_contained_item.getName()) {
			contain = true;
		}
	}

  return contain;
}