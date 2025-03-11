#ifndef CREATE_H
#define CREATE_H

#include "Listing.h"

// Forward declaration for CarDealership
class CarDealership;

class Create {
public:
    Listing* createListing(CarDealership& dealership, const std::string& username); // Accept username
};

#endif