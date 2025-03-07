#include "Browse.h"
#include <iostream>

void Browse::display(const vector<Listing*>& listings) {
    cout << "Browse Listings:\n";
    for (const auto& listing : listings) {
        listing->display();
        cout << "-----------------\n";
    }
}