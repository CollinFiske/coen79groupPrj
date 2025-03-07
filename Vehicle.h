#ifndef VEHICLE_H
#define VEHICLE_H

#include "Listing.h"

class Vehicle : public Listing {
public:
    string make;
    string model;
    int year;
    int miles;
    string condition;

    Vehicle(string n, double bin, double b, string u, string mk, string md, int y, int mi, string c, bool assignId = true); // Updated constructor
    void display() const override;
};

#endif
