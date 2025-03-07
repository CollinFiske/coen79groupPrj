#include "Create.h"
#include "Part.h"
#include "Vehicle.h"
#include <iostream>

Listing* Create::createListing() {
    int id, type, quantity, year, miles;
    string name, user, make, model, condition;
    double buyItNow, bid;

    cout << "Enter listing type (1 for Part, 2 for Vehicle): ";
    cin >> type;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Buy It Now price: $";
    cin >> buyItNow;
    cout << "Enter starting bid: $";
    cin >> bid;
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, user);


    
    if (type == 1) {
        cout << "Enter quantity: ";
        cin >> quantity;
        return new Part(rand() % 1000, name, buyItNow, bid, user, quantity);
    } else {
        cout << "Enter make: ";
        cin.ignore();
        getline(cin, make);
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter miles: ";
        cin >> miles;
        cout << "Enter condition: ";
        cin.ignore();
        getline(cin, condition);
        return new Vehicle(rand() % 1000, name, buyItNow, bid, user, make, model, year, miles, condition);
    }
}