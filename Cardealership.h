#ifndef CARDEALERSHIP_H
#define CARDEALERSHIP_H

#include <vector>
#include <string>
#include "Listing.h"
#include "Bid.h"
#include "Browse.h"

// Forward declaration for Create class
class Create;

class CarDealership {
private:
    std::vector<Listing*> listings;
    Browse browse;
    Bid bid;
    Create* create; // Use a pointer to avoid incomplete type issues

    const std::string filename = "listings.txt"; // File to store listings

public:
    CarDealership();
    ~CarDealership();
    void run();
    void saveListings() const; // Save listings to file
    void loadListings();       // Load listings from file
};

#endif
