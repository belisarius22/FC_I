// File: hw2.3.cpp
// Author(s): Jordan Giebas, Daniel Rojas

#include <iostream>
using namespace std;

/* original code from lecture notes */
void put_int_bits(unsigned i)
{
	if (i == 0) {   // stopping condition
		cout << 0;  // leading 0 bit
	}
	else {
		put_int_bits(i / 2);  // hard task
		cout << i % 2;        // easy task
	}
}

/* improved version from part (b) */
void put_int_n_bits(unsigned i, unsigned n)
{
	if (n) {
		put_int_n_bits(i / 2, n - 1);  // hard task
		cout << i % 2;                 // easy task
	}
}

void put_int_bits_v2(unsigned i)
{
	// assume 8 bits per byte
	const size_t bits_per_int = sizeof(int) * 8;
	put_int_n_bits(i, bits_per_int);
}

/* function definition for part (d), from lecture notes */
void put_rev_str_it(char *s) {  // iterative version
	
	char* end = s;
	int length = 0;
	while (*end) {
		end += 1;
		length += 1;
	}
	
	for (int i = 1; i <=length; i++) {
		cout << s[length - i];
	}

}

void put_rev_str_rc(char *s) {  // recursive version
	if (*s) {                   // if there is a char
		put_rev_str_rc(s + 1);    // put trailing chars
		cout << *s;             // then current char
	}
}


void put_int_with_commas(int i) {

	if (i < 0) {
		
		if (i == INT_MIN) {
			cout << "-2,147,483,648";
			return;
		}
		cout << "-";
		i = abs(i);
	}
	int first = i % 1000;
	int last = i / 1000;

	if (last > 0) {
		put_int_with_commas(last);
		cout << "," << first;
	}
	else {
		cout << first;
	}

}

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

int main()
{
	cout << "_____PART A_____ \n\n";
	put_int_bits(0);    // 0
	cout << "\n";
	put_int_bits(7);    // 0111
	cout << "\n";
	put_int_bits(1234); // 010011010010
	cout << "\n";
	put_int_bits(-1);   // 011111111111111111111111111111111
	cout << "\n";

	// code for part (b)
	cout << "_____PART B_____ \n\n";
	put_int_bits_v2(0);    // 0
	cout << "\n";
	put_int_bits_v2(7);    // 0111
	cout << "\n";
	put_int_bits_v2(1234); // 010011010010
	cout << "\n";
	put_int_bits_v2(-1);   // 011111111111111111111111111111111
	cout << "\n";
	

	// code for part (c)
	
	cout << "_____PART C_____ \n\n";
	put_int_with_commas(0); cout << '\n';
	put_int_with_commas(1); cout << '\n';
	put_int_with_commas(12); cout << '\n';
	put_int_with_commas(123); cout << '\n';
	put_int_with_commas(1234); cout << '\n';
	put_int_with_commas(12345); cout << '\n';
	put_int_with_commas(123456); cout << '\n';
	put_int_with_commas(1234567); cout << '\n';
	put_int_with_commas(12345678); cout << '\n';
	put_int_with_commas(123456789); cout << '\n';
	put_int_with_commas(1234567890); cout << '\n';
	put_int_with_commas(INT_MAX); cout << '\n';
	put_int_with_commas(-1); cout << '\n';
	put_int_with_commas(-12); cout << '\n';
	put_int_with_commas(-123); cout << '\n';
	put_int_with_commas(-1234); cout << '\n';
	put_int_with_commas(-12345); cout << '\n';
	put_int_with_commas(-123456); cout << '\n';
	put_int_with_commas(-1234567); cout << '\n';
	put_int_with_commas(-12345678); cout << '\n';
	put_int_with_commas(-123456789); cout << '\n';
	put_int_with_commas(-1234567890); cout << '\n';
	put_int_with_commas(INT_MIN); cout << '\n';
	
	
	
	//code for part (d)
	cout << "_____PART D_____ \n\n";
	char hello[] = "Hello World!";

	cout << "Iterative \n\n";

	put_rev_str_it(hello);
	cout << "\n";

	cout << "\nRecursive \n\n";

	put_rev_str_rc(hello);
	cout << "\n\n";

	cout << "We think the iterative one would be more intuitive except for the 'while' that needs to find the end of the array. If this part could be abstracted (for instance with a 'length_of_array(.)' function), then iterative would be more simple.\n";

	return 0;
}

