#include "listing.h"

class part : listing {

    part(int q){
        quantity = q;
    }

    private:
        int quantity;


    public:
    //GETTER
        int getQuantity(){ return quantity; }

    //SETTER
        void setQuantity(int q){ quantity = q; }

};
