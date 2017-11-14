// File: hw1.1.cpp
// Author(s):
/*
 * Jordan Giebas
 * _____
 * _____
 */


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    cout << "part (a):\n";

    /*
     * Part (a): I'm making it through all iterations of the loop,
     * in both my terminal with vim and g++ command and in CLION.
     * - JG
     *
     * When I increase each of the memory allocations by a factor of 10
     * I make it through the first 108253 iterations of the loop.
     *
     */

    for (int i(1); i <= 1000000; ++i) { // 1 million times

        int *pi = new int[100000000];     // 10 million ints
        double *pd = new double[100000000];  // 10 million doubles
        char *pc = new char[100000000];    // 10 million chars

        cout << "i: " << setw(7) << i << '\n';

        // ... but no delete[] statements!
        // Memory leak! adding now


        delete[] pi;
        delete[] pd;
        delete[] pc;

    }

    /*
     * Part (b): I'm still making it all the way through, I feel like nothing's changed.
     * It must be that my compiler is immediately deleting these things for me? I'm unsure,
     * I'll email Prof. Ostlund
     * - JG (10/28/17)
     *
     * After Prof. Ostlund's instruction to increase the allocations, I am now seeing
     * the difference. With the appropriate delte operators, the for loop iteratres through its
     * entire range.
     */

    cout << "Part (c):\n";

    // Part (c):

    int *iptr = new int {-123};  // declare pointer (i)
    cout << *iptr << endl;      // print value (ii)
    cout << &iptr << endl;      // print address of (iii)
    delete iptr;                // delete obj (iv)

    // Part (d):

    /*
    cout << *iptr << endl;      // The value is still -123 (i)
    //delete iptr;              // An error occurs: "pointer being freed was not allocated" (ii)
    *iptr = 1234;
    cout << *iptr << endl;      // When I reassign 1234 to iptr it points to that value (iii)
    */

    // this code is for part (e)

    /*
    cout << "\npart (e):\n";

    for (int i(0); i < 10; ++i) {

        cout << "before allocation " << i << "\n";
        char *pc = new(nothrow) char[50000000000000];
        cout << "after allocation -- ";

        cout << (pc == nullptr ? "new returned nullptr\n" : "new did NOT return nullptr\n");

    }
     */

    /*
     * Part (e):
     *  When I run the code as is (I switched it to ternary structure for practice, and since I'm on a mac
     *  I also had to increase the size of the memory requested by 10^5 so that it would result in bad_alloc,
     *  there was an error thrown during the 2nd iteration.
     */

    /*
     * Part (f):
     *  When I add the (nothrow) constant after the "new" command, I am able to go through each iteration
     *  of the loop. But every iteration of the loop after the second returns nullptr, which is sensible since
     *  we expect a bad_alloc to be thrown and a nullptr returned instead.
     */

    // Part (g):

    int test = 10'000'000;
    cout << "test: " << test;

    // Yes, it works as expected


}



