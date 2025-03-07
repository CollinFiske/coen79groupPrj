#ifndef PART_H
#define PART_H

#include "Listing.h"

class Part : public Listing {
public:
    int quantity;
    Part(int id, string n, double bin, double b, string u, int q);
    void display() const override;
};

#endif