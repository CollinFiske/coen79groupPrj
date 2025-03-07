#include "Listing.h"
#include <iostream>

// Initialize the static counter
int Listing::lastUsedId = 0;

// Updated constructor to control ID assignment
Listing::Listing(string n, double bin, double b, string u, bool assignId)
    : name(n), buyItNow(bin), bid(b), user(u) {
    if (assignId) {
        UUid = ++lastUsedId; // Automatically assign ID
    } else {
        UUid = 0; // Temporary value, will be overwritten
    }
}

void Listing::display() const {
    cout << "ID: " << UUid << "\nName: " << name << "\nBuy It Now: $" << buyItNow
         << "\nCurrent Bid: $" << bid << "\nUser: " << user << endl;
}

// Method to reset lastUsedId
void Listing::setLastUsedId(int id) {
    lastUsedId = id;
}
