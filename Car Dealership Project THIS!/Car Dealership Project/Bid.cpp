#include "Bid.h"
#include <iostream>
#include <limits>

void Bid::display(Listing* item) {
    std::cout << "Bid on Item:\n";
    item->display();

    std::cout << "\nOptions:\n";
    std::cout << "1. Place Bid\n";
    std::cout << "2. Buy It Now ($" << item->buyItNow << ")\n";
    std::cout << "Choose an option: ";

    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 2) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid option. Please enter 1 or 2: ";
    }

    if (choice == 1) {
        double newBid;
        std::cout << "Enter your bid: $";
        while (!(std::cin >> newBid) || newBid < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number: $";
        }

        if (newBid > item->buyItNow) {
            std::cout << "Your bid exceeds the Buy It Now price. You have purchased the item!\n";
            item->bid = newBid;
            item->user = "SOLD"; // Mark the item as sold
        } else if (newBid > item->bid) {
            item->bid = newBid;
            std::cout << "Bid successful!\n";
        } else {
            std::cout << "Bid must be higher than the current bid.\n";
        }
    } else if (choice == 2) {
        std::cout << "You have purchased the item for $" << item->buyItNow << "!\n";
        item->bid = item->buyItNow; // Set the bid to the Buy It Now price
        item->user = "SOLD"; // Mark the item as sold
    }
}