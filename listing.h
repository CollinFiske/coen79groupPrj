
class listing {

public:
  listing search();
  

};


#include "listing.h"

class listing {


    private:
        int UUid;
        int quantity;
        double buyItNow;
        double bid;
        

    public:
    //GETTERS
        listing search();
        int getUUid();

        
        double getName();

        
        int getQuantity();

        
        double getBIN();

        
        double getBid();
            
        
    //SETTERS
        void setUUid();

        
        void setName();

        
        void setQuantity();

        
        void setBIN();

        
        void setBid();
          
        




};
