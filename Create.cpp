#include "Create.h"
#include "Cardealership.h"
#include "Part.h"
#include "Vehicle.h"
#include <iostream>
#include <limits> // For numeric_limits

Listing* Create::createListing(CarDealership& dealership) {
    int type, quantity, year, miles;
    string name, user, make, model, condition;
    double buyItNow, bid;

    // Input validation for listing type
    cout << "Enter listing type (1 for Part, 2 for Vehicle): ";
    while (!(cin >> type) || (type != 1 && type != 2)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter 1 for Part or 2 for Vehicle: ";
    }

    // Input validation for name
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    // Input validation for Buy It Now price
    cout << "Enter Buy It Now price: $";
    while (!(cin >> buyItNow) || buyItNow < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive number: $";
    }

    // Input validation for starting bid
    cout << "Enter starting bid: $";
    while (!(cin >> bid) || bid < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive number: $";
    }

    // Input validation for username
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, user);

    if (type == 1) {
        // Input validation for quantity
        cout << "Enter quantity: ";
        while (!(cin >> quantity) || quantity < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer: ";
        }
        return new Part(name, buyItNow, bid, user, quantity);
    } else {
        // Input validation for vehicle details
        cout << "Enter make: ";
        cin.ignore();
        getline(cin, make);

        cout << "Enter model: ";
        getline(cin, model);

        cout << "Enter year: ";
        while (!(cin >> year) || year < 1886) { // First car was made in 1886
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid year (1886 or later): ";
        }

        cout << "Enter miles: ";
        while (!(cin >> miles) || miles < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number: ";
        }

        cout << "Enter condition: ";
        cin.ignore();
        getline(cin, condition);

        return new Vehicle(name, buyItNow, bid, user, make, model, year, miles, condition);
    }
}
