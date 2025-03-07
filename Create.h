#ifndef CREATE_H
#define CREATE_H

// Forward declaration for CarDealership
class CarDealership;

#include "Listing.h"

class Create {
public:
    Listing* createListing(CarDealership& dealership); // Accept CarDealership reference
};

#endif
