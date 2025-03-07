#ifndef BROWSE_H
#define BROWSE_H

#include <vector>
#include "Listing.h"

class Browse {
public:
    void display(const std::vector<Listing*>& listings); // Display listings with pagination
};

#endif
