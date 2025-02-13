#include "listing.h"

class vehicle : listing {

    vehicle(){
        
    }

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
        void setMake( string m ){ make = m; }
        void setModel(string m ){ model = m; }
        void setYear( int y ){ year = y; }
        void setMiles( int y ){ miles = y; }
        void setCondition( string c ){ condition = c; }




};
