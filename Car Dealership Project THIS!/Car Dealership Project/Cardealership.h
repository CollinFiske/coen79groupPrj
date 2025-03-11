#ifndef CARDEALERSHIP_H
#define CARDEALERSHIP_H

#include <vector>
#include <string>
#include "Listing.h"
#include "Bid.h"
#include "Browse.h"
#include "Create.h"
#include "User.h"

// Forward declaration for Create class
class Create;

class CarDealership {
private:
    std::vector<Listing*> listings;
    std::vector<User*> users; // Store all users
    Browse browse;
    Bid bid;
    Create* create; // Use a pointer to avoid incomplete type issues
    User* currentUser; // Track the logged-in user

    const std::string listingsFilename = "listings.txt"; // File to store listings
    const std::string usersFilename = "users.txt"; // File to store users

public:
    CarDealership();
    ~CarDealership();
    void run();
    void saveListings() const; // Save listings to file
    void loadListings();       // Load listings from file
    void login();              // Handle user login
    void createAccount();      // Handle user account creation
    void saveUsers() const;    // Save users to file
    void loadUsers();          // Load users from file
    void mainMenu();           // Main menu after login
    void removeListing(int id); // Remove a listing by ID
    void editListings();       // Edit listings
    void endAuction();         // End an auction manually
};

#endif