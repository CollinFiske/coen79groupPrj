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

    Listing(int id, string n, double bin, double b, string u);
    virtual void display() const;
};

#endif