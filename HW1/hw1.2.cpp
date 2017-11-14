// File: hw1.2.cpp
// Author(s):

#include <iostream>
#include <iomanip>
using namespace std;

struct Stock {
    char ticker[8];  // leave some extra space
    int id;          // my firm's ID for this stock
    double price;
};

struct Portfolio {
    Stock *stocks;   // the "array" of Stocks
    int *num_owned;  // can sell short, so int
    size_t nstocks;  // number of stocks, >= 0
};

void put_Stock(Stock *ps) {
    cout << setw(8) << ps->ticker << setw(4) << (*ps).id
         << setw(10) << ps[0].price;
}

int main()
{
    Stock apple{ "AAPL", 0, 162.45 },
          vmware{ "VMW", 1, 120.08 },
          ibm{ "IBM", 2, 153.72 },
          alcoa{ "AA", 3, 47.71 },
          ford{ "F", 4, 12.07 };
    Portfolio p1{ new Stock[3]{ apple, ibm, ford},
                  new int[3]{ 20, 10, -5 },
                  3 };

    cout << "Portfolio:\n";
    for (int i(0); i < p1.nstocks; ++i) {
        put_Stock(p1.stocks + i);
        cout << setw(10) << p1.num_owned[i] << '\n';
    }

    *(p1.num_owned + 2) -= 10;

    cout << "\nModified portfolio:\n";
    for (int i(0); i < p1.nstocks; ++i) {
        put_Stock(p1.stocks + i);
        cout << setw(10) << p1.num_owned[i] << '\n';
    }

    delete[] p1.stocks;
    delete[] p1.num_owned;
}

