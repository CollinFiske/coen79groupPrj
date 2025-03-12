# Car Dealership Project

This project is an application for a mock car dealership with auctioning functionality for parts and cars. It allows users to create accounts, log in, browse listings, bid on items, create new listings, edit existing listings, and end auctions. 

## Files

- `Bid.cpp` and `Bid.h`: Implements the bidding functionality.
- `Browse.cpp` and `Browse.h`: Implements the browsing functionality with pagination.
- `Cardealership.cpp` and `Cardealership.h`: Main class that manages the car dealership operations.
- `Create.cpp` and `Create.h`: Implements the creation of new listings.
- `Listing.cpp` and `Listing.h`: Base class for listings.
- `Part.cpp` and `Part.h`: Derived class for parts listings.
- `Vehicle.cpp` and `Vehicle.h`: Derived class for vehicle listings.
- `main.cpp`: Entry point of the application.
- `listings.txt`: Stores the listings data.
- `users.txt`: Stores the users data.

## How to Run

1. Compile the project using a C++ compiler.
       `ex. g++ .\main.cpp .\Bid.cpp .\Browse.cpp .\Cardealership.cpp .\Create.cpp .\Listing.cpp .\Part.cpp .\Vehicle.cpp -o example`
3. Run the executable `prj.exe`.

## Features

- **User Management**: Create accounts and log in.
- **Browse Listings**: Browse available listings with pagination.
- **Bid on Items**: Place bids on items or buy them immediately.
- **Create Listings**: Create new listings for parts or vehicles.
- **Edit Listings**: Edit existing listings.
- **End Auctions**: End auctions manually.

## Usage

1. **Login or Create Account**: Start by logging in or creating a new account.
2. **Main Menu**: After logging in, you can browse listings, bid on items, create new listings, edit your listings, or end auctions.
3. **Browse Listings**: View available listings with pagination.
4. **Bid on Items**: Place a bid or buy an item immediately.
5. **Create Listings**: Add new parts or vehicles to the listings.
6. **Edit Listings**: Modify your existing listings.
7. **End Auctions**: End an auction and mark the item as sold.

## Data Persistence

- **Users**: User data is stored in `users.txt`.
- **Listings**: Listings data is stored in `listings.txt`.

## Example Data

### users.txt

### listings.txt

## License

This project is licensed under the MIT License.



