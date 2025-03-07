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

    Vehicle(int id, string n, double bin, double b, string u, string mk, string md, int y, int mi, string c);
    void display() const override;
};

#endif