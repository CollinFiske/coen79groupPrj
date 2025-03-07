#include "Cardealership.h"
#include "Part.h"
#include "Vehicle.h"
#include "Create.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits> // For numeric_limits

CarDealership::CarDealership() {
    create = new Create(); // Initialize the Create object
}

CarDealership::~CarDealership() {
    for (auto& listing : listings) {
        delete listing;
    }
    delete create; // Clean up the Create object
}

// Rest of the CarDealership.cpp implementation remains the same

void CarDealership::run() {
    loadListings(); // Load listings from file when the program starts
    while (true) {
        cout << "\n1. Browse Listings\n2. Bid on Item\n3. Create Listing\n4. Exit\nChoose an option: ";
        int choice;
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid option. Please enter a number between 1 and 4: ";
        }

        if (choice == 1) {
            if (listings.empty()) {
                cout << "No listings available. Please create a listing first.\n";
            } else {
                browse.display(listings);
            }
        } else if (choice == 2) {
            if (listings.empty()) {
                cout << "No listings available. Please create a listing first.\n";
            } else {
                int id;
                cout << "Enter the ID of the item you want to bid on: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid ID: ";
                }

                bool found = false;
                for (auto& listing : listings) {
                    if (listing->UUid == id) {
                        bid.display(listing);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Item with ID " << id << " not found.\n";
                }
            }
        } else if (choice == 3) {
            listings.push_back(create->createListing(*this)); // Use -> instead of .
        } else if (choice == 4) {
            saveListings(); // Save listings to file before exiting
            break;
        }
    }
}

void CarDealership::saveListings() const {
    std::ofstream file(filename);
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
    std::ifstream file(filename);
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
