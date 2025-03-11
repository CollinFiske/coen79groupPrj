#include "Cardealership.h"
#include "Part.h"
#include "Vehicle.h"
#include "Create.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

CarDealership::CarDealership() : currentUser(nullptr) {
    create = new Create(); // Initialize the Create object
    loadUsers(); // Load users from file
    loadListings(); // Load listings from file
}

CarDealership::~CarDealership() {
    for (auto& listing : listings) {
        delete listing;
    }
    delete create; // Clean up the Create object
    delete currentUser; // Clean up the current user
}

void CarDealership::run() {
    while (true) {
        std::cout << "\n1. Login\n2. Create Account\n3. Exit\nChoose an option: ";
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid option. Please enter a number between 1 and 3: ";
        }

        if (choice == 1) {
            login();
            if (currentUser) {
                mainMenu(); // Proceed to the main menu after successful login
            }
        } else if (choice == 2) {
            createAccount();
        } else if (choice == 3) {
            saveListings(); // Save listings to file before exiting
            saveUsers();    // Save users to file before exiting
            break;
        }
    }
}

void CarDealership::removeListing(int id) {
    for (auto it = listings.begin(); it != listings.end(); ++it) {
        if ((*it)->UUid == id) {
            delete *it; // Free the memory
            listings.erase(it); // Remove the listing from the vector
            std::cout << "Listing removed.\n";
            return;
        }
    }
    std::cout << "Listing with ID " << id << " not found.\n";
}

void CarDealership::editListings() {
    if (!currentUser) {
        std::cout << "You must be logged in to edit listings.\n";
        return;
    }

    // Display the user's listings
    std::cout << "Your Listings:\n";
    bool hasListings = false;
    for (const auto& listing : listings) {
        if (listing->user == currentUser->username) {
            listing->display();
            std::cout << "-----------------\n";
            hasListings = true;
        }
    }

    if (!hasListings) {
        std::cout << "You have no listings to edit.\n";
        return;
    }

    // Prompt the user to choose a listing to edit
    int id;
    std::cout << "Enter the ID of the listing you want to edit: ";
    while (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid ID: ";
    }

    // Find the listing
    Listing* listingToEdit = nullptr;
    for (auto& listing : listings) {
        if (listing->UUid == id && listing->user == currentUser->username) {
            listingToEdit = listing;
            break;
        }
    }

    if (!listingToEdit) {
        std::cout << "Listing with ID " << id << " not found or you do not have permission to edit it.\n";
        return;
    }

    // Edit the listing
    std::cout << "Editing Listing ID " << id << ":\n";
    std::cout << "1. Edit Name\n";
    std::cout << "2. Edit Buy It Now Price\n";
    std::cout << "3. Edit Starting Bid\n";
    if (auto part = dynamic_cast<Part*>(listingToEdit)) {
        std::cout << "4. Edit Quantity\n";
    } else if (auto vehicle = dynamic_cast<Vehicle*>(listingToEdit)) {
        std::cout << "4. Edit Make\n";
        std::cout << "5. Edit Model\n";
        std::cout << "6. Edit Year\n";
        std::cout << "7. Edit Miles\n";
        std::cout << "8. Edit Condition\n";
    }
    std::cout << "Choose an option: ";

    int choice;
    while (!(std::cin >> choice) || choice < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid option: ";
    }

    switch (choice) {
        case 1: {
            std::string newName;
            std::cout << "Enter new name: ";
            std::cin.ignore();
            std::getline(std::cin, newName);
            listingToEdit->name = newName;
            break;
        }
        case 2: {
            double newBuyItNow;
            std::cout << "Enter new Buy It Now price: $";
            while (!(std::cin >> newBuyItNow) || newBuyItNow < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a positive number: $";
            }
            listingToEdit->buyItNow = newBuyItNow;
            break;
        }
        case 3: {
            double newBid;
            std::cout << "Enter new starting bid: $";
            while (!(std::cin >> newBid) || newBid < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a positive number: $";
            }
            listingToEdit->bid = newBid;
            break;
        }
        case 4: {
            if (auto part = dynamic_cast<Part*>(listingToEdit)) {
                int newQuantity;
                std::cout << "Enter new quantity: ";
                while (!(std::cin >> newQuantity) || newQuantity < 1) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a positive integer: ";
                }
                part->quantity = newQuantity;
            } else if (auto vehicle = dynamic_cast<Vehicle*>(listingToEdit)) {
                std::string newMake;
                std::cout << "Enter new make: ";
                std::cin.ignore();
                std::getline(std::cin, newMake);
                vehicle->make = newMake;
            }
            break;
        }
        case 5: {
            if (auto vehicle = dynamic_cast<Vehicle*>(listingToEdit)) {
                std::string newModel;
                std::cout << "Enter new model: ";
                std::cin.ignore();
                std::getline(std::cin, newModel);
                vehicle->model = newModel;
            }
            break;
        }
        case 6: {
            if (auto vehicle = dynamic_cast<Vehicle*>(listingToEdit)) {
                int newYear;
                std::cout << "Enter new year: ";
                while (!(std::cin >> newYear) || newYear < 1886) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid year (1886 or later): ";
                }
                vehicle->year = newYear;
            }
            break;
        }
        case 7: {
            if (auto vehicle = dynamic_cast<Vehicle*>(listingToEdit)) {
                int newMiles;
                std::cout << "Enter new miles: ";
                while (!(std::cin >> newMiles) || newMiles < 0) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a positive number: ";
                }
                vehicle->miles = newMiles;
            }
            break;
        }
        case 8: {
            if (auto vehicle = dynamic_cast<Vehicle*>(listingToEdit)) {
                std::string newCondition;
                std::cout << "Enter new condition: ";
                std::cin.ignore();
                std::getline(std::cin, newCondition);
                vehicle->condition = newCondition;
            }
            break;
        }
        default:
            std::cout << "Invalid option.\n";
            break;
    }

    std::cout << "Listing updated successfully.\n";
}

void CarDealership::endAuction() {
    if (!currentUser) {
        std::cout << "You must be logged in to end an auction.\n";
        return;
    }

    // Display the user's listings
    std::cout << "Your Listings:\n";
    bool hasListings = false;
    for (const auto& listing : listings) {
        if (listing->user == currentUser->username && listing->user != "SOLD") {
            listing->display();
            std::cout << "-----------------\n";
            hasListings = true;
        }
    }

    if (!hasListings) {
        std::cout << "You have no active listings to end.\n";
        return;
    }

    // Prompt the user to choose a listing to end
    int id;
    std::cout << "Enter the ID of the listing you want to end: ";
    while (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid ID: ";
    }

    // Find the listing
    Listing* listingToEnd = nullptr;
    for (auto& listing : listings) {
        if (listing->UUid == id && listing->user == currentUser->username && listing->user != "SOLD") {
            listingToEnd = listing;
            break;
        }
    }

    if (!listingToEnd) {
        std::cout << "Listing with ID " << id << " not found or you do not have permission to end it.\n";
        return;
    }

    // End the auction
    listingToEnd->user = "SOLD"; // Mark the item as sold
    std::cout << "Auction ended. The highest bidder wins!\n";
}

void CarDealership::mainMenu() {
    while (true) {
        std::cout << "\n1. Browse Listings\n2. Bid on Item\n3. Create Listing\n4. Edit Listings\n5. End Auction\n6. Logout\nChoose an option: ";
        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid option. Please enter a number between 1 and 6: ";
        }

        if (choice == 1) {
            if (listings.empty()) {
                std::cout << "No listings available. Please create a listing first.\n";
            } else {
                browse.display(listings);
            }
        } else if (choice == 2) {
            if (listings.empty()) {
                std::cout << "No listings available. Please create a listing first.\n";
            } else {
                int id;
                std::cout << "Enter the ID of the item you want to bid on: ";
                while (!(std::cin >> id)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid ID: ";
                }

                bool found = false;
                for (auto& listing : listings) {
                    if (listing->UUid == id) {
                        bid.display(listing);
                        if (listing->user == "SOLD") {
                            removeListing(id); // Remove the listing if it's sold
                        }
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Item with ID " << id << " not found.\n";
                }
            }
        } else if (choice == 3) {
            listings.push_back(create->createListing(*this, currentUser->username)); // Pass the logged-in user's username
        } else if (choice == 4) {
            editListings(); // Edit listings
        } else if (choice == 5) {
            endAuction(); // End an auction
        } else if (choice == 6) {
            currentUser = nullptr; // Log out the user
            break;
        }
    }
}


void CarDealership::login() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    for (const auto& user : users) {
        if (user->username == username && user->password == password) {
            currentUser = user;
            std::cout << "Login successful. Welcome, " << username << "!\n";
            return;
        }
    }

    std::cout << "Invalid username or password.\n";
}

void CarDealership::createAccount() {
    std::string username, password;
    std::cout << "Enter a new username: ";
    std::cin >> username;
    std::cout << "Enter a new password: ";
    std::cin >> password;

    // Check if the username already exists
    for (const auto& user : users) {
        if (user->username == username) {
            std::cout << "Username already exists. Please choose a different username.\n";
            return;
        }
    }

    // Create a new user and add it to the list
    User* newUser = new User(username, password);
    users.push_back(newUser);
    std::cout << "Account created successfully.\n";
}

void CarDealership::saveUsers() const {
    std::ofstream file(usersFilename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to save users to file.\n";
        return;
    }

    // Save all users to the file
    for (const auto& user : users) {
        file << user->username << "," << user->password << "\n";
    }

    file.close();
    std::cout << "Users saved to file.\n";
}

void CarDealership::loadUsers() {
    std::ifstream file(usersFilename);
    if (!file.is_open()) {
        std::cerr << "No existing users file found. Starting with an empty list.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string username, password;
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');

        // Add the user to the list
        users.push_back(new User(username, password));
    }

    file.close();
    std::cout << "Users loaded from file.\n";
}

void CarDealership::saveListings() const {
    std::ofstream file(listingsFilename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to save listings to file.\n";
        return;
    }

    // Save the last used ID
    file << "LastUsedId:" << Listing::lastUsedId << "\n";

    for (const auto& listing : listings) {
        file << listing->UUid << ","
             << listing->name << ","
             << listing->buyItNow << ","
             << listing->bid << ","
             << listing->user;

        if (auto part = dynamic_cast<Part*>(listing)) {
            file << ",Part," << part->quantity;
        } else if (auto vehicle = dynamic_cast<Vehicle*>(listing)) {
            file << ",Vehicle," << vehicle->make << ","
                 << vehicle->model << ","
                 << vehicle->year << ","
                 << vehicle->miles << ","
                 << vehicle->condition;
        }

        file << "\n";
    }

    file.close();
    std::cout << "Listings saved to file.\n";
}

void CarDealership::loadListings() {
    std::ifstream file(listingsFilename);
    if (!file.is_open()) {
        std::cerr << "No existing listings file found. Starting with an empty list.\n";
        return;
    }

    std::string line;
    bool lastUsedIdLoaded = false; // Flag to check if LastUsedId has been loaded
    int maxId = 0; // Track the maximum ID in the file

    while (std::getline(file, line)) {
        if (!lastUsedIdLoaded && line.find("LastUsedId:") == 0) {
            // Extract the last used ID
            int lastUsedId = std::stoi(line.substr(11));
            Listing::setLastUsedId(lastUsedId); // Restore the last used ID
            lastUsedIdLoaded = true; // Mark LastUsedId as loaded
            std::cout << "Loaded LastUsedId: " << lastUsedId << "\n"; // Debug output
            continue;
        }

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 6) continue; // Skip invalid lines

        int id = std::stoi(tokens[0]);
        std::string name = tokens[1];
        double buyItNow = std::stod(tokens[2]);
        double bid = std::stod(tokens[3]);
        std::string user = tokens[4];

        // Track the maximum ID in the file
        if (id > maxId) {
            maxId = id;
        }

        if (tokens[5] == "Part" && tokens.size() == 7) {
            int quantity = std::stoi(tokens[6]);
            // Create the Part object without assigning an ID
            Part* part = new Part(name, buyItNow, bid, user, quantity, false);
            part->UUid = id; // Manually set the ID from the file
            listings.push_back(part);
        } else if (tokens[5] == "Vehicle" && tokens.size() == 11) {
            std::string make = tokens[6];
            std::string model = tokens[7];
            int year = std::stoi(tokens[8]);
            int miles = std::stoi(tokens[9]);
            std::string condition = tokens[10];
            // Create the Vehicle object without assigning an ID
            Vehicle* vehicle = new Vehicle(name, buyItNow, bid, user, make, model, year, miles, condition, false);
            vehicle->UUid = id; // Manually set the ID from the file
            listings.push_back(vehicle);
        }
    }

    // Update lastUsedId to the maximum ID found in the file
    if (maxId > Listing::lastUsedId) {
        Listing::setLastUsedId(maxId);
        std::cout << "Updated LastUsedId to: " << maxId << "\n"; // Debug output
    }

    file.close();
    std::cout << "Listings loaded from file.\n";
}