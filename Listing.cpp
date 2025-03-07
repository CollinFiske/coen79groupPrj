#include "Listing.h"
#include <iostream>

Listing::Listing(int id, string n, double bin, double b, string u)
    : UUid(id), name(n), buyItNow(bin), bid(b), user(u) {}

void Listing::display() const {
    cout << "ID: " << UUid << "\nName: " << name << "\nBuy It Now: $" << buyItNow
         << "\nCurrent Bid: $" << bid << "\nUser: " << user << endl;
}