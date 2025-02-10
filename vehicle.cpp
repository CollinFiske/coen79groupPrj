#include "listing.h"

class vehicle : listing {


    private:
        
        string make;
        string model;
        int year;
        int miles;
        string condition;
        

    public:
    //GETTERS
        string getMake(){ return make; }
        string getModel(){ return model; }
        int getYear(){ return year; }
        int getMiles(){ return miles; }
        string getCondition(){}

    //SETTERS
        void setMake(){ }
        void setModel(){  }
        void setYear(){  }
        void setMiles(){ }
        void setCondition(){}




};
