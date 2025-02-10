

class listing {


    private:
        int UUid;
        string name;
        double buyItNow;
        double bid;
        string user;
        

    public:
    //GETTERS
        listing search();
        int getUUid();
        double getName();
        double getBIN();
        double getBid();
        string getUser();
        
    //SETTERS
        void setUUid();
        void setName();
        void setBIN();
        void setBid();
        void setUser();

};
