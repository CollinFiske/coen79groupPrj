#ifndef LISTING_H
#define LISTING_H

#include <string>
using namespace std;

class Listing {
public:
    int UUid;
    string name;
    double buyItNow;
    double bid;
    string user;

    static int lastUsedId; // Static counter for unique IDs

    Listing(string n, double bin, double b, string u, bool assignId = true); // Updated constructor
    virtual void display() const;

    // Method to reset lastUsedId (for loading from file)
    static void setLastUsedId(int id);
};

#endif
