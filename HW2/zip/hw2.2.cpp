// File: hw2.2.cpp
// Author(s):Jordan Giebas, Daniel Rojas Coy 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double pi(3.1415926535897932);
	const double *ppi{ &pi };

	cout << fixed << setprecision(15);

	cout << "pi:    " << pi << '\n';
	cout << "&pi:   " << &pi << '\n';
	cout << "ppi:   " << ppi << '\n';
	cout << "*ppi:  " << *ppi << '\n';

	// code for part (b)
	//const double e;
	cout << "b) Compilation fails because a constant must be initialized." << endl;

	// code for part (c)
	const double e(2.7182818284590452);
	cout << "e:     " << e << '\n';
	
	// code for part (d)
	//double *pe(&e);  // pe points to e
	cout << "d) Compilation fails because it is a non-constant pointer pointing to a constant." << endl;

	// code for part (e)
	double *pe((double *)&e);  // force pe to point to e
	cout << "pe:    " << pe << '\n';    // address of e
	cout << "*pe:   " << *pe << '\n';   // value of e
	

	// code for part (f)
	*pe = pi;		// change e to pi?
	cout << "*pe:   " << *pe << '\n';   // is e now pi?
	cout << "f) Yes, e seems to be pi now." << endl;

	// code for part (g)
	cout << "e:     " << e << '\n';    // is e now pi?
	cout << "&e:    " << &e << '\n';   // address of e
	cout << "pe:    " << pe << '\n';   // same as address of e?
	cout << "*pe:   " << *pe << '\n';  // value of e?
	cout << "e) e is still Euler's number. &e and pe are the same adress. However *pe is pi. Weird!\n";

	return 0;
}

