#ifndef CARDEALERSHIP_H
#define CARDEALERSHIP_H

#include <vector>
#include <string>
#include "Listing.h"
#include "Bid.h"
#include "Browse.h"
#include "Create.h"

class CarDealership {
private:
    std::vector<Listing*> listings;
    Browse browse;
    Bid bid;
    Create create;

    const std::string filename = "listings.txt"; // File to store listings

public:
    void run();
    void saveListings() const; // Save listings to file
    void loadListings();       // Load listings from file
    ~CarDealership();         // Destructor to clean up dynamic memory
};

#endif