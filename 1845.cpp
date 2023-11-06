class SeatManager 
{
public:
    set<int>st;
    SeatManager(int n) 
    {
        for(int i=0;i<n;i++)
        {
            st.insert(i+1);
        }
    }
    
    int reserve() 
    {
        int v=(*st.begin());
        st.erase(v);
        return v;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};
