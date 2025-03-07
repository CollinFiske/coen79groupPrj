#include "Part.h"
#include <iostream>

Part::Part(int id, string n, double bin, double b, string u, int q)
    : Listing(id, n, bin, b, u), quantity(q) {}

void Part::display() const {
    Listing::display();
    cout << "Quantity: " << quantity << endl;
}