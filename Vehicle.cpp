#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int id, string n, double bin, double b, string u, string mk, string md, int y, int mi, string c)
    : Listing(id, n, bin, b, u), make(mk), model(md), year(y), miles(mi), condition(c) {}

void Vehicle::display() const {
    Listing::display();
    cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year
         << "\nMiles: " << miles << "\nCondition: " << condition << endl;
}