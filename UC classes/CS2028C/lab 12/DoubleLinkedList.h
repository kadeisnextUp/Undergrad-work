#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
using namespace std;


template <class T>
class DoubleLinkedList {
	private:
		struct listNode {
			T *value;
			struct listNode *next;
			struct listNode	*prev;
		};
		listNode *head;
		listNode *tail;
		listNode *next;
	public:
		//constructor
		DoubleLinkedList() {
			head = nullptr;
			tail = nullptr;
			next = head;

		}

		//destructor
		~DoubleLinkedList();

		

		void addItem(T *item);
		T* getItem(T *item);
		bool IsInList(T *item);
		bool IsEmpty();
		int size();
		T* seeNext();
		T* seePrev();
		T* seeAt(int index);
		void reset();
		void display();

		//soriting algorithms
		void sortByFirstName(bool ascend = true);
		void sortByLastName(bool ascend = true);
		void sortByMNumber(bool ascend = true);


};

// destructor
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	listNode* nodePtr = head;
	while (nodePtr != nullptr) {
		listNode* temp = nodePtr;
		nodePtr = nodePtr->next;
		delete temp->value;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
	next = nullptr;
}


/* bubble sort by first name*/
template <class T>
void DoubleLinkedList<T>::sortByFirstName(bool ascend) {
	if (IsEmpty()) return;

	bool swapped;
	do {
		swapped = false;
		listNode* current = head;

		while (current && current->next) {
			string a = current->value->getFirstName();
			string b = current->next->value->getFirstName();
			bool condition = ascend ? (a > b) : (a < b);

			if (condition) {
				swap(current->value, current->next->value);
				swapped = true;
			}
			current = current->next;
		}
	} while (swapped);

}

/* insertion sort by last name*/
template <class T>
void DoubleLinkedList<T>::sortByLastName(bool ascend) {
	if (IsEmpty() || head->next == nullptr) return;

	listNode* sorted = nullptr;

	listNode* curr = head;
	while (curr) {
		listNode* next = curr->next;

		// Insert curr into sorted list
		if (!sorted) {
			curr->prev = curr->next = nullptr;
			sorted = curr;
		}
		else {
			listNode* insertPos = sorted;
			while (insertPos) {
				string a = curr->value->getLastName();
				string b = insertPos->value->getLastName();
				bool condition = ascend ? (a < b) : (a > b);

				if (condition) break;
				insertPos = insertPos->next;
			}

			if (!insertPos) {
				// Insert at end
				listNode* tailSorted = sorted;
				while (tailSorted->next) tailSorted = tailSorted->next;
				tailSorted->next = curr;
				curr->prev = tailSorted;
				curr->next = nullptr;
			}
			else if (insertPos == sorted) {
				// Insert at beginning
				curr->next = sorted;
				curr->prev = nullptr;
				sorted->prev = curr;
				sorted = curr;
			}
			else {
				// Insert in middle
				curr->prev = insertPos->prev;
				curr->next = insertPos;
				insertPos->prev->next = curr;
				insertPos->prev = curr;
			}
		}

		curr = next;
	}

	// Fix head and tail
	head = sorted;
	tail = head;
	while (tail && tail->next) tail = tail->next;
}

/*selection sort by mNumber*/
template <class T>
void DoubleLinkedList<T>::sortByMNumber(bool ascend) {
	if (IsEmpty()) return;

	for (listNode* i = head; i != nullptr; i = i->next) {
		listNode* target = i;
		for (listNode* j = i->next; j != nullptr; j = j->next) {
			int a = j->value->getMnumber();
			int b = target->value->getMnumber();
			bool condition = ascend ? (a < b) : (a > b);
			if (condition) {
				target = j;
			}
		}
		if (target != i) {
			swap(i->value, target->value);
		}
	}
}

/*adds an item from the list*/
template <class T>
void DoubleLinkedList<T>::addItem(T *item) {
	listNode* tempNode;
	listNode* nodePtr;
	listNode* previousNode;

	tempNode = new listNode;
	tempNode->value = item;
	tempNode->next = nullptr;
	tempNode->prev = nullptr;

	// if list is empty point the head and tail to tempNode
	if (IsEmpty()) {
		head = tempNode;
		tail = tempNode;
	}
	else {
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < item) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//if you are at the beginning of the list insert the node in front
		if (previousNode == nullptr) {
			tempNode->next = head;
			head->prev = tempNode;
			head = tempNode;
			
		}
		// if at the end of the list
		else if(nodePtr == nullptr) {
			previousNode->next = tempNode;
			tempNode->prev = previousNode;
			tail = tempNode;
		}
		// somewhere in the middle of the list
		else {
			previousNode->next = tempNode;
			tempNode->next = nodePtr;
			tempNode->prev = previousNode;
			nodePtr->prev = tempNode;
		}

	}



}




/* searches the list for the given item. If found, it removes it from
the list and returns it. If not found, it returns a null pointer. */

template <class T>
T* DoubleLinkedList<T>::getItem(T *item) {
	listNode* nodePtr;

	nodePtr = head;
	//traversing through the list until we find the item
	while (nodePtr != nullptr && nodePtr->value != item) {
		nodePtr = nodePtr->next;
	}
	// the item wasn't in the list so return null
	if (nodePtr == nullptr) { return nullptr; }
	//if the item was at the head the new head of the list would be the next item
	if (nodePtr == head) {
		head = nodePtr->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
	}
	//if the item was at the tail the new tail would be the item before that
	else if (nodePtr == tail) {
		tail = nodePtr->prev;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
	}
	/*if in the middle of the list somewhere connect the previous node to the next node and 
	connect the next node to the previous to completely disconnect the wanted node*/
	else {
		nodePtr->prev->next = nodePtr->next;
		nodePtr->next->prev = nodePtr->prev;

	}
	//make a new pointer to the wanted item
	T* itemPtr = (nodePtr->value);

	delete nodePtr;
	return itemPtr;

}


/*returns a bool indicating if the given item is in the list. */

template <class T>
bool DoubleLinkedList<T>::IsInList(T *item) {
	listNode* nodePtr = head;


	while(nodePtr != nullptr) {
		//if the value is greater then the item there's no reason to traverse farther in a ordered list
		if (nodePtr->value > item) {
			return false;
		}

		if (nodePtr->value == item) {
			return true;
		}
		
		nodePtr = nodePtr->next;
	}
	//if it exists the loop return false because the item was never found
	return false;
	


}



/*returns a bool indicating if the list is empty.*/
template <class T>
bool DoubleLinkedList<T>::IsEmpty() {
	return head == nullptr;
}


/*returns an int indicating the number of items in the list.*/
template <class T>
int DoubleLinkedList<T>::size() {
	listNode* nodePtr = head;
	int count = 0;
	while (nodePtr != nullptr) {
		count++;
		nodePtr = nodePtr->next;
	}
	return count;
}



/*returns the item without removing it from the list at a given
location in the list. The class will maintain the next location and will start
at the first item in the list. When it gets to the last item in the list, it will
return a null pointer after it gets past the last item. If the list is empty, this
will throw an error. 2 calls to SeeNext will return the 2 items next to each
other in the list unless SeeAt or Reset is called in between the 2 calls (or
the first call returns the last item in the list or the list is modifed between
the two calls).*/

template <class T>
T* DoubleLinkedList<T>::seeNext() {
	if (IsEmpty()) {
		throw std::runtime_error("List is empty");

	}
	if (next == nullptr) {
		return nullptr;
	}
	T* result = next->value;
	next = next->next;
	return result;

}


/*Same as SeeNext except in the other direction*/
template <class T>
T* DoubleLinkedList<T>::seePrev() {
	if (IsEmpty()) {
		throw std::runtime_error("List is empty");

	}
	if (next == nullptr || next->prev == nullptr) {
		return nullptr;
	}
	T* result = (next->value);
	next = next->prev;
	return result;



}



/* Finds an item at a location in the list (int passed in from user), and
returns the item without removing it. If the location passed by the user is
past the end of the list, this will throw an error. This will set the location
used by SeeNext to point at the item after the item returned*/
template <class T>
T* DoubleLinkedList<T>::seeAt(int index) {
	if (IsEmpty()) {
		throw std::runtime_error("List is empty");
	}
	//invalid index
	if (index < 0) {
		throw std::out_of_range("Index out of range");
	}

	listNode* nodePtr = head;
	int count = 0;

	while (nodePtr != nullptr && count < index) {
		nodePtr = nodePtr->next;
		count++;
	}

	if (nodePtr == nullptr) {
		throw std::out_of_range("Index out of range");
	}

	// point to the next item after the found one
	next = nodePtr->next;

	return nodePtr->value;


}



/*resets the location variable that the SeeNext function uses so the
next call to SeeNext will return the first item in the list*/
template <class T>
void DoubleLinkedList<T>::reset() {
	next = head;
}

/*This method should write directly to the screen*/
template <class T>
void DoubleLinkedList<T>::display() {
	listNode* nodePtr = head;
	while (nodePtr != nullptr) {
		//assuming the T has a display method
		nodePtr->value->Display(); 
		nodePtr = nodePtr->next;
	}
}



#endif
