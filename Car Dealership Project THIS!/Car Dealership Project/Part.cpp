#include "Part.h"
#include <iostream>

// Updated constructor
Part::Part(string n, double bin, double b, string u, int q, bool assignId)
    : Listing(n, bin, b, u, assignId), quantity(q) {}

void Part::display() const {
    Listing::display();
    cout << "Quantity: " << quantity << endl;
}