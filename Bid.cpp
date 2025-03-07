#include "Bid.h"
#include <iostream>

void Bid::display(Listing* item) {
    cout << "Bid on Item:\n";
    item->display();
    double newBid;
    cout << "Enter your bid: $";
    cin >> newBid;
    if (newBid > item->bid) {
        item->bid = newBid;
        cout << "Bid successful!\n";
    } else {
        cout << "Bid must be higher than current bid.\n";
    }
}