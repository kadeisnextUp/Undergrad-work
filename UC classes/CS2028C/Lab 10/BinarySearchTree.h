#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <algorithm> // for max function
#include <stdexcept> // for thrown errors
using namespace std;

template <class T>
class BinarySearchTree {
	private:
		struct treeNode {
			T value;
			treeNode* right;
			treeNode* left;
			int height;

            //constuctor for the node
            treeNode(T val) : value(val), left(nullptr), right(nullptr), height(0) {}

		};
		//top of the tree
		treeNode* root;
	

	public:
        //required functions 
        treeNode* insert(treeNode* node, T item);
        T* find(T item);
        int size() const;
        void getAllAscending() const;
        void getAllDescending() const;
        void emptyTree(treeNode* node);
        treeNode* remove(treeNode* node, const T& value, bool& success);

        //other helper functions
        treeNode* balance(treeNode* node);
        int height(treeNode* node) const;
        int getBalanceFactor(treeNode* node) const;
        int getSize(treeNode* node) const;
        void inOrder(treeNode* node) const;
        void printNodeInfo(treeNode* node) const;
        void reverseInOrder(treeNode* node) const;
        void checkRemove(const T& value);
        treeNode* getMinValueNode(treeNode* node);

		//constructor
		BinarySearchTree() { root = nullptr; }

		//destructor
		~BinarySearchTree() {
            emptyTree(root);
		}

		//insert root
		void insert(T item) {
			root = insert(root, item);
		}

};

/* insert
		*
		* accepts a value, creates a node, and inserts the node into the tree in the
			appropriate location. This should rebalance the tree as necessary, so the tree
			remains balanced at all times. If the value already exists in the tree, this should
			throw an error.
		*/
template <class T>
typename BinarySearchTree<T>::treeNode* BinarySearchTree<T>::insert(treeNode* node, T item){
	//base case	
	if (node == nullptr)
		return new treeNode(item);
	//recursion
	if (item < node->value)
		node->left = insert(node->left, item);
	else if (item > node->value)
		node->right = insert(node->right, item);
	else
		throw runtime_error("Duplicate value");

	return balance(node);

}

//height helper gets the height of node
template <class T>
int BinarySearchTree<T>::height(treeNode* node) const {
	return node ? node->height : -1;
}

//balance factor used in the balance fucntion
template <class T>
int BinarySearchTree<T>::getBalanceFactor(treeNode* node) const {
	return height(node->left) - height(node->right);
}

//balacne fucntion incorporates all rotations instead of having different rotation functions
template <class T>
typename BinarySearchTree<T>::treeNode* BinarySearchTree<T>::balance(treeNode* node) {
  
    if (!node) return nullptr;

    // calculating heights
    int leftHeight = (node->left) ? node->left->height : -1;
    int rightHeight = (node->right) ? node->right->height : -1;

    // updating the node's height
    node->height = 1 + max(leftHeight, rightHeight);

    int balanceFactor = leftHeight - rightHeight;

    // if the tree is left heavy 
    if (balanceFactor > 1) {
        int leftLeftHeight = (node->left && node->left->left) ? node->left->left->height : -1;
        int leftRightHeight = (node->left && node->left->right) ? node->left->right->height : -1;

        // left-Right Case: rotate left on left child
        if (leftRightHeight > leftLeftHeight) {
            // rotate left on node->left 
            treeNode* oldLeft = node->left;
            node->left = oldLeft->right;
            oldLeft->right = node->left->left;
            node->left->left = oldLeft;

            // recalculate heights
            oldLeft->height = 1 + max(
                (oldLeft->left) ? oldLeft->left->height : -1,
                (oldLeft->right) ? oldLeft->right->height : -1
            );
            node->left->height = 1 + max(
                (node->left->left) ? node->left->left->height : -1,
                (node->left->right) ? node->left->right->height : -1
            );
        }

        // left-left case: rotate right on node
        treeNode* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        // recalculate heights
        node->height = 1 + max(
            (node->left) ? node->left->height : -1,
            (node->right) ? node->right->height : -1
        );
        newRoot->height = 1 + max(
            (newRoot->left) ? newRoot->left->height : -1,
            (newRoot->right) ? newRoot->right->height : -1
        );

        return newRoot;
    }

    // if tree is right heavy
    else if (balanceFactor < -1) {
        int rightLeftHeight = (node->right && node->right->left) ? node->right->left->height : -1;
        int rightRightHeight = (node->right && node->right->right) ? node->right->right->height : -1;

        // right-left case : rotate right on right child
        if (rightLeftHeight > rightRightHeight) {
            treeNode* oldRight = node->right;
            node->right = oldRight->left;
            oldRight->left = node->right->right;
            node->right->right = oldRight;

            // recalculate heights
            oldRight->height = 1 + max(
                (oldRight->left) ? oldRight->left->height : -1,
                (oldRight->right) ? oldRight->right->height : -1
            );
            node->right->height = 1 + max(
                (node->right->left) ? node->right->left->height : -1,
                (node->right->right) ? node->right->right->height : -1
            );
        }

        // right-right case: rotate left on node
        treeNode* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        // recalculate heights
        node->height = 1 + max(
            (node->left) ? node->left->height : -1,
            (node->right) ? node->right->height : -1
        );
        newRoot->height = 1 + max(
            (newRoot->left) ? newRoot->left->height : -1,
            (newRoot->right) ? newRoot->right->height : -1
        );

        return newRoot;
    }

    // the tree is balanced
    return node;
}

/* find
*	accepts a value, locates the value in the tree and returns a pointer to the
	node. If the value isn’t in the tree, it will return a null pointer.
*/
template <class T>
T* BinarySearchTree <T> ::find(T item) {
	treeNode* nodePtr = root;

	while (nodePtr) {
        if (nodePtr->value == item) {
            //true
            return &(nodePtr->value);
        }
           

		else if (item < nodePtr->value) {
			nodePtr = nodePtr->left;
		}
		else {
			nodePtr = nodePtr->right;
		}
	}
	//false
	return nullptr;
}

/* size()
* returns the number of elements in the tree as an integer using getSize()
*/
template <class T>
int BinarySearchTree <T>:: size() const {
    return getSize(root);
}

/*
* getSize()
* helper function to actually get the size of the tree
*/
template <class T>
int BinarySearchTree <T> :: getSize(treeNode* node) const {
    if (!node) return 0;
    return 1 + getSize(node->left) + getSize(node->right);
}

/* getAllAscending()
*   returns an array with each node stored in order from smallest
    to largest (based on the sorting value, not the other data in the node).
*/
template <class T>
void BinarySearchTree <T> :: getAllAscending() const {
    cout << "Ascending:\n";
    inOrder(root);
}

/* inOrder()
* helper function to getAllAscending()
*/
template <class T>
void BinarySearchTree <T> :: inOrder(treeNode* node) const {
    if (!node) return;
    inOrder(node->left);
    printNodeInfo(node);  // prints the value, height, & balance
    inOrder(node->right);
}

/* printNodeInfor()
* print balance factor and height
*/
template <class T>
void BinarySearchTree <T> :: printNodeInfo(treeNode* node) const {
    cout << node->value << " (Height: " << node->height
     << ", Balance Factor: " << getBalanceFactor(node) << ")\n";
}

/* getAllDescending()
* returns an array with each node stored in order from largest
    to smallest (based on the sorting value, not the other data in the node)
*/
template <class T>
void BinarySearchTree <T> :: getAllDescending() const {
    cout << "Descending:\n";
    reverseInOrder(root);
}

/* reverseInOrder()
* helper function for getAllDescending()
*/
template <class T>
void BinarySearchTree <T> :: reverseInOrder(treeNode* node) const {
    if (!node) return;
    reverseInOrder(node->right);
    printNodeInfo(node);  // prints the value, height, & balance
    reverseInOrder(node->left);
}

/* emptyTree()
* removes all nodes in the tree in a way to avoid memory leaks
*/
template <class T>
void BinarySearchTree <T> ::emptyTree(treeNode* node) {
        if (!node) return;
        emptyTree(node->left);
        emptyTree(node->right);
        delete node;
        node = nullptr;
}

/* checkRemove()
* checks to see if the value is in the tree  and will use the remove funciton if so
*/
template <class T>
void BinarySearchTree <T> :: checkRemove(const T& value) {
    bool success = false;
    root = remove(root, value, success);
    if (!success)
        throw runtime_error("Value is not found.");
}

/* getMinValueNode()
    gets the smallest value node and returns the pointer to it
*/
template <class T>
typename BinarySearchTree<T>::treeNode* BinarySearchTree<T> ::getMinValueNode(treeNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

/* remove()
* accepts a value from the user, finds the value, and removes it from the
    tree. A pointer to the removed node is returned. This should rebalance the tree as
    necessary, so the tree remains balanced at all times

    returns a balanced tree after removal
    */
template <class T>
typename BinarySearchTree<T>::treeNode* BinarySearchTree <T> ::remove(treeNode* node, const T& value, bool& success) {
    if (!node) {
        success = false;
        return nullptr;
    }

    if (value < node->value)
        node->left = remove(node->left, value, success);
    else if (value > node->value)
        node->right = remove(node->right, value, success);
    else {
        success = true;
        if (!node->left || !node->right) {
            treeNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        treeNode* successor = getMinValueNode(node->right);
        node->value = successor->value;
        node->right = remove(node->right, successor->value, success);
    }

    return balance(node);
}

#endif
