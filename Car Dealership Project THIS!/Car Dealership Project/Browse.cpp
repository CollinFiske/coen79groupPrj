#include "Browse.h"
#include <iostream>
#include <limits>

void Browse::display(const std::vector<Listing*>& listings) {
    const int listingsPerPage = 5; // Number of listings per page
    int totalPages = (listings.size() + listingsPerPage - 1) / listingsPerPage; // Calculate total pages
    int currentPage = 1; // Start at the first page

    while (true) {
        // Clear the screen (optional, for better readability)
        #ifdef _WIN32
            system("cls"); // For Windows
        #else
            system("clear"); // For Linux/Mac
        #endif

        // Display the current page
        std::cout << "Page " << currentPage << " of " << totalPages << ":\n";
        int startIndex = (currentPage - 1) * listingsPerPage;
        int endIndex = std::min(startIndex + listingsPerPage, static_cast<int>(listings.size()));

        if (startIndex >= listings.size()) {
            std::cout << "No listings to display.\n";
        } else {
            for (int i = startIndex; i < endIndex; i++) {
                listings[i]->display();
                std::cout << "-----------------\n";
            }
        }

        // Display navigation options
        std::cout << "\nOptions:\n";
        std::cout << "1. Next Page\n";
        std::cout << "2. Previous Page\n";
        std::cout << "3. Exit Browse\n";
        std::cout << "Choose an option: ";

        int choice;
        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid option. Please enter a number between 1 and 3: ";
        }

        // Handle the user's choice
        if (choice == 1) {
            if (currentPage < totalPages) {
                currentPage++; // Go to the next page
            } else {
                std::cout << "You are already on the last page.\n";
            }
        } else if (choice == 2) {
            if (currentPage > 1) {
                currentPage--; // Go to the previous page
            } else {
                std::cout << "You are already on the first page.\n";
            }
        } else if (choice == 3) {
            break; // Exit browse mode
        }
    }
}