
// File: hw2.1.cpp
// Author(s):

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// clist structure definition

struct cl_node {
	char data;
	cl_node *next;
};

// clist creation functions

cl_node *mk_clist_from_Cstring(const char *s)
{
	cl_node *first(nullptr);
	cl_node *last(nullptr);
	for (; *s; ++s) {
		cl_node *pnew = new cl_node{ *s, nullptr };
		if (!last) {
			last = first = pnew;
		}
		else {
			last = last->next = pnew;
		}
	}
	return first;
}

// clist access functions

size_t clist_size(const cl_node *cl)
{
	size_t size(0);
	for (; cl; cl = cl->next)
		size += 1;
	return size;
}

void clist_display_to_cout(const cl_node *cl)
{
	for (; cl; cl = cl->next)
		cout << cl->data;
}

// clist element modification functions

void clist_to_uppercase(cl_node *cl)
{
	// assumes ASCII character set
	for (; cl; cl = cl->next) {
		if ('a' <= cl->data && cl->data <= 'z') {
			cl->data -= 'a' - 'A';
		}
	}
}

// clist deletion function (a shape modifying function)

void clist_delete(cl_node **p_cl)
{
	while (*p_cl) {
		cl_node *tmp = *p_cl;
		*p_cl = (*p_cl)->next;
		delete tmp;
	}
}

// Part b

cl_node* mk_copy_clist(const cl_node* cl) {

	cl_node *first(nullptr);
	cl_node *last(nullptr);

	for (; cl; cl = cl->next) {
		cl_node *pnew = new cl_node{ cl->data, nullptr };
		if (!last) {
			last = first = pnew;
		}
		else {
			last = last->next = pnew;
		}
	}
	return first;

}


// Part c

cl_node *mk_clist_from_string(const string str)
{
	const char* s = str.c_str();

	cl_node *first(nullptr);
	cl_node *last(nullptr);
	for (; *s; ++s) {
		cl_node *pnew = new cl_node{ *s, nullptr };
		if (!last) {
			last = first = pnew;
		}
		else {
			last = last->next = pnew;
		}
	}
	return first;
}

// Part d

void clist_append_char(cl_node** p_cl, const char c)
{

	if (!*p_cl) {
		cl_node* pnew = new cl_node{ c,nullptr };
		*p_cl = pnew;
	}
	else
	{
		cl_node* temp = *p_cl;
		for (; temp; temp = temp->next) {
			if (!temp->next) {
				cl_node* pnew = new cl_node{ c,nullptr };
				temp->next = pnew;
				break;
			}
		}
	}
}

// Part e


size_t clist_count_char(const cl_node *cl, const char c)
{
	size_t size(0);
	for (; cl; cl = cl->next) {
		if (cl->data == c) {
			size += 1;
		}
	}
		
	return size;
}

// Part f

void clist_delete_dups(cl_node** p_cl)
{

	cl_node* temp = *p_cl;
	
	for (; temp; temp = temp->next) {

		if (!temp->next) {
			break;
		}

		if (temp->data == (temp->next)->data) {
			cl_node* erase = temp->next;
			temp->next = (temp->next)->next;
			delete erase;
			erase = 0;
		}
		// This won't work if there is an odd number of consecutive duplicate letters
	}

}

// Part g

void clist_insert_clist(cl_node** p_cl, cl_node* cl2, int pos) {
	
	cl_node* temp = *p_cl;

	for(int i=0; i<(pos-1); i++) {
		temp = temp->next;
	}

	cl_node* coda = temp->next;
	
	temp->next = mk_copy_clist(cl2);
	
	while(temp->next){
		temp = temp->next;
	}

	temp->next = coda;
}

// Part h

cl_node* mk_empty_clist() {
	cl_node* cl = nullptr;
	return cl;
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////



int main()
{
	//code for part (a)
	cout << "_____PART A_____ \n\n";
	cl_node *bob = mk_clist_from_Cstring("Bob");
	clist_display_to_cout(bob);    // Bob
	cout << '\n';
	cout << "list is " << clist_size(bob) << " chars long\n";
	clist_to_uppercase(bob);
	clist_display_to_cout(bob);    // BOB
	cout << '\n';
	clist_delete(&bob);
	clist_display_to_cout(bob);    // (empty -- no memory leak)

	//code for part (b)
	cout << "_____PART B_____ \n\n";
	cl_node *hello = mk_clist_from_Cstring("hello");
	clist_display_to_cout(hello); cout << '\n';  // hello
	cl_node *hello2 = mk_copy_clist(hello);
	clist_display_to_cout(hello2); cout << '\n'; // hello
	clist_to_uppercase(hello2);
	clist_display_to_cout(hello); cout << '\n';  // hello
	clist_display_to_cout(hello2); cout << '\n'; // HELLO
	clist_delete(&hello);
	clist_delete(&hello2);
	clist_display_to_cout(hello);  // (empty)
	clist_display_to_cout(hello2); // (empty)

								   

	//code for part (c)
	cout << "_____PART C_____ \n\n";
	string s("howdy");
	cl_node *howdy = mk_clist_from_string(s);
	clist_display_to_cout(howdy); cout << '\n';  // howdy
	clist_delete(&howdy);
	clist_display_to_cout(howdy);  // (empty)

	

	// code for part (d)
	cout << "_____PART D_____ \n\n";
	cl_node *cl = mk_clist_from_Cstring("Bell");
	clist_display_to_cout(cl); cout << '\n';     // Bell
	clist_append_char(&cl, 'a');
	clist_display_to_cout(cl); cout << '\n';     // Bella
	clist_delete(&cl);
	clist_display_to_cout(cl);                   // (empty)
	clist_append_char(&cl, 'X');
	clist_display_to_cout(cl); cout << '\n';     // X
	clist_delete(&cl);
	clist_display_to_cout(cl);                   // (empty)


	//code for part (e)
	cout << "_____PART E_____ \n\n";
	cl_node *cl2 = mk_clist_from_Cstring("Mississippi");
	clist_display_to_cout(cl2); cout << '\n';    // Mississippi
	cout << clist_count_char(cl2, 'i') << '\n';  // 4

	

	// code for part (f)
	cout << "_____PART F_____ \n\n";
	clist_display_to_cout(cl2); cout << '\n';    // Mississippi
	clist_delete_dups(&cl2);
	clist_display_to_cout(cl2); cout << '\n';    // Misisipi
	clist_delete(&cl2);
	clist_display_to_cout(cl2); cout << '\n';    // (empty)

	

	// code for part (g)
	cout << "_____PART G_____ \n\n";
	cl_node *cl3 = mk_clist_from_Cstring("national");
	cl_node *cl4 = mk_clist_from_Cstring("ive fic");
	clist_insert_clist(&cl3, cl4, 2);
	clist_display_to_cout(cl3); cout << '\n'; // naive fictional
	clist_display_to_cout(cl4); cout << '\n'; // ive fic
	clist_delete(&cl3);
	clist_delete(&cl4);

	

	// code for part (h)
	cout << "_____PART H_____ \n\n";
	cl_node *cl5 = mk_empty_clist();
	clist_display_to_cout(cl5); cout << '\n'; // (empty)
	clist_append_char(&cl5, 'h');
	clist_append_char(&cl5, 'i');
	clist_display_to_cout(cl5); cout << '\n'; // hi
	clist_delete(&cl5);

}

