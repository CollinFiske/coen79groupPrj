

class listing {


    private:
        int UUid;
        string name;
        double buyItNow;
        double bid;
        

    public:
    //GETTERS
        listing search();
        int getUUid();
        double getName();
        double getBIN();
        double getBid();
        
    //SETTERS
        void setUUid();
        void setName();
        void setBIN();
        void setBid();

};
