#ifndef PART_H
#define PART_H

#include "Listing.h"

class Part : public Listing {
public:
    int quantity;

    Part(string n, double bin, double b, string u, int q, bool assignId = true); // Updated constructor
    void display() const override;
};

#endif