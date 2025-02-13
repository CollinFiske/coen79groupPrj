

    listing(){}
    listing(int UUid, int name, double buyItNow, double bid, string user){
      UUid = UUid;
      name = name;
      buyItNow = buyItNow;
      bid = bid;
      user = user;
    }

    listing search(){}

//GETTERS
    int getUUid(){ return UUid; }
    double getName(){ return name; }
    double getBIN(){ return buyItNow; }
    double getBid(){ return bid; }
    string getUser(){ return user; }
    
//SETTERS
    void setUUid( int n ){ UUid = n; }
    void setName( string n ){ name = n; }
    void setBIN( double n ){ buyItNow = n; }
    void setBid( double n ){ bid = n; }
    void setUser( string n ){ name = n; }
