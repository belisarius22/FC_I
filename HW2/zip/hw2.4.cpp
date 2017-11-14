// File: hw2.4.cpp
// Author(s): Jordan Giebas, Daniel Rojas Coy

#include <iostream>
using namespace std;

struct bt_node {
	int value;       // the current values
	bt_node *left;   // lower values to the left
	bt_node *right;  // higher values to the right
};

void put_binary_tree(const bt_node *top)
{
	if (top) {
		put_binary_tree(top->left);
		cout << top->value << " ";
		put_binary_tree(top->right);
	}
}

void binary_tree_insert(bt_node **ptop, int val)
{
	if (*ptop) {  // we are not at the bottom yet
		if (val < (*ptop)->value) // left for less than
			binary_tree_insert(&(*ptop)->left, val);
		else      // right for greater than or equal to
			binary_tree_insert(&(*ptop)->right, val);
	}
	else {
		*ptop = new bt_node{ val, 0, 0 };
	}
}

void binary_tree_delete(bt_node **ptop)
{
	if (*ptop) {
		if ((*ptop)->left)
			binary_tree_delete(&(*ptop)->left);
		if ((*ptop)->right)
			binary_tree_delete(&(*ptop)->right);
		delete *ptop;
		*ptop = 0;
	}
}

bool binary_tree_is_empty(const bt_node *top)
{
	return top == 0;    // or top == nullptr;
}

int binary_tree_min(const bt_node *top)
{
	if (binary_tree_is_empty(top))
		return 0;      // a reasonable default?
	for (; top->left; top = top->left)
		;
	return top->value;
}

///////////////////////////////////////////////

// part b

void put_binary_tree_rev(const bt_node *top){
	if (top) {
		put_binary_tree_rev(top->right);
		cout << top->value << " ";
		put_binary_tree_rev(top->left);
	}
}

// part c

bool binary_tree_contains(const bt_node *top, int val) {
	if (top) {
		if ((*top).value == val) {
			return 1;
		}
		else if ((*top).value > val) {
			binary_tree_contains(top->left, val);
		}
		else {
			binary_tree_contains(top->right, val);
		}
	}
	else {
		return 0;
	}
}

// part d

void put_binary_tree_pretty(const bt_node *top, int level = 0)
{
	if (top) {
		put_binary_tree_pretty(top->right, level + 1);
		for (int i = 0; i < level; i++) {
			cout << "\t";
		}
		cout << top->value << "\n";
		put_binary_tree_pretty(top->left, level + 1);
	}
}

// part e

void binary_tree_insert_unique(bt_node **ptop, int val)
{
	if (*ptop) {  // we are not at the bottom yet
		if (val == (*ptop)->value) return;

		if (val < (*ptop)->value) // left for less than
			binary_tree_insert_unique(&(*ptop)->left, val);
		else      // right for greater than or equal to
			binary_tree_insert_unique(&(*ptop)->right, val);
	}
	else {
		*ptop = new bt_node{ val, 0, 0 };
	}
}

// part f

size_t binary_tree_size(const bt_node *top) {
	
	if (top) {
		return 1 + binary_tree_size(top->left) + binary_tree_size(top->right);
	}
	else {
		return 0;
	}
}

// part g

int binary_tree_sum(const bt_node *top) {

	if (top) {
		return top->value + binary_tree_sum(top->left) + binary_tree_sum(top->right);
	}
	else {
		return 0;
	}
}

// part h

double binary_tree_mean(const bt_node *top) {
	if (top) {
		return binary_tree_sum(top) / double(binary_tree_size(top));
	}
	else {
		return DBL_MIN;
	}
}

// part g

bt_node* rightmost(bt_node* ptop) {

	while (ptop->right) {
		ptop = ptop->right;
	}
	return(ptop);
}

void binary_tree_delete_value(bt_node **ptop, int val) {

	// Case 0: Empty tree
	if (!*ptop) return;

	// current is the one to be deleted
	// previous is the parent node
	bt_node* current = *ptop;
	bt_node* previous = nullptr;

	// Direction to move from previous to current 0 left, 1 right
	bool direction = 0;

	// Find nodes with value 'val'
	while (current) {
		if (current->value == val) {
			break;
		} 
		else if (current->value > val) {
			previous = current;
			current = current->left;
			direction = 0;
		}
		else {
			previous = current;
			current = current->right;
			direction = 1;
		}
	}


	// If there is no node with that value, the function ends
	if (current == nullptr) return;

	// If there is no previous, it means the node to be deleted is the root
	if (previous == nullptr) {
		//Rightmost of left subtree
		bt_node* lr = rightmost(current->left);
		lr->right = (current->right);
		// The original pointer is modified
		*ptop = current->left;
		delete current;

	} //If the node to be deleted is a leave, then the pointer of the previous is just deleted
	else if (current->left==nullptr && current->right == nullptr) {
		if (direction) {
			previous->right = nullptr;
		}
		else {
			previous->left = nullptr;
		}
		delete current;
	} // if there is something to the left
	else if (current->left) {
		// check if there is a node to the right and move it to the rightmost node on the left sub tree
		if (current->right) {
			bt_node* lr = rightmost(current->left);
			lr->right = (current->right);
		}
		// The pointer that used to go to current, now goes to the left subtree
		if (direction) {
			previous->right = current->left;
		}
		else {
			previous->left = current->left;
		}
		delete current;
	} // if there is only stuff to the right
	else if (current->right) {
		// Put the right sub tree where current used to be
		if (direction) {
			previous->right = current->right;
		}
		else {
			previous->left = current->right;
		}
		delete current;

	}

	// Runs the function again in case the value is repeated. 
	// If it only shows once the if after the while will stop the function
	binary_tree_delete_value(ptop, val);
	
}

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

int main()
{
	bt_node *top = 0;  // tree, initially empty

	binary_tree_insert(&top, 12);  // why &top?
	binary_tree_insert(&top, 7);
	binary_tree_insert(&top, -4);
	binary_tree_insert(&top, 13);
	binary_tree_insert(&top, 9);
	binary_tree_insert(&top, 29);

	put_binary_tree(top);
	cout << "\n";

	cout << "Is binary tree empty? ";
	if (binary_tree_is_empty(top)) {
		cout << "yes!\n";
	}
	else {
		cout << "no\n";
	}

	cout << "Minimum value in binary tree is: " << binary_tree_min(top) << "\n";

	// code for part (b)
	cout << "binary tree values in reverse:\n";
	put_binary_tree_rev(top);
	cout << '\n';
	

	// code for part (c)
	cout << boolalpha;
	cout << "binary tree contains 13: "
	<< binary_tree_contains(top, 13) << '\n';
	cout << "binary tree contains -7: "
	<< binary_tree_contains(top, -7) << '\n';


	// code for part (d)
	cout << "pretty binary tree:\n";
	put_binary_tree_pretty(top);
	

	// code for first half of part (e)
	cout << "three more 7s:\n";
	binary_tree_insert(&top, 7);
	binary_tree_insert(&top, 7);
	binary_tree_insert(&top, 7);
	put_binary_tree_pretty(top);
	

	// code for second half of part (e)
	cout << "new tree, unique values:\n";
	bt_node *top2 = nullptr;
	binary_tree_insert_unique(&top2, 7);
	binary_tree_insert_unique(&top2, 4);
	binary_tree_insert_unique(&top2, 12);
	binary_tree_insert_unique(&top2, 7);
	binary_tree_insert_unique(&top2, 7);
	binary_tree_insert_unique(&top2, 9);
	binary_tree_insert_unique(&top2, 9);
	binary_tree_insert_unique(&top2, 12);
	binary_tree_insert_unique(&top2, 12);
	binary_tree_insert_unique(&top2, 4);
	binary_tree_insert_unique(&top2, 2);
	binary_tree_insert_unique(&top2, 2);
	put_binary_tree_pretty(top2);

	
	// code for part (f)
	bt_node *top3 = nullptr;
	cout << "top size: " << binary_tree_size(top) << "\n";
	cout << "top2 size: " << binary_tree_size(top2) << "\n";
	cout << "top3 size: " << binary_tree_size(top3) << "\n";
	
	
	// code for part (g)
	cout << "top sum: " << binary_tree_sum(top) << "\n";
	cout << "top2 sum: " << binary_tree_sum(top2) << "\n";
	cout << "top3 sum: " << binary_tree_sum(top3) << "\n";

	// code for part (h)
	cout << "top mean: " << binary_tree_mean(top) << "\n";
	cout << "top2 mean: " << binary_tree_mean(top2) << "\n";
	cout << "top3 mean: " << binary_tree_mean(top3) << "\n";


	/* 
	//Our tests
	bt_node *top6 = nullptr;
	binary_tree_insert_unique(&top6, 8);
	binary_tree_insert_unique(&top6, 2);
	binary_tree_insert_unique(&top6, 9);
	binary_tree_insert_unique(&top6, 1);
	binary_tree_insert_unique(&top6, 4);
	binary_tree_insert_unique(&top6, 3);
	binary_tree_insert_unique(&top6, 5);
	binary_tree_insert_unique(&top6, 11);
	binary_tree_insert(&top6, 9);
	binary_tree_insert(&top6, 4);
	put_binary_tree_pretty(top6);
	binary_tree_delete_value(&top6, 9);
	cout << "---------------------\n";
	put_binary_tree_pretty(top6);
	binary_tree_delete_value(&top6, 4);
	cout << "---------------------\n";
	put_binary_tree_pretty(top6);
	*/

	// code for part (i)
	binary_tree_delete_value(&top, 7);
	binary_tree_delete_value(&top2, 7);
	cout << "top with 7 deleted:\n";
	put_binary_tree_pretty(top);
	cout << "top2 with 7 deleted:\n";
	put_binary_tree_pretty(top2);
	
	binary_tree_delete(&top3);  // properly deallocate top3
	binary_tree_delete(&top2);
	binary_tree_delete(&top);  // no memory leaks!
}

