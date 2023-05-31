class UndergroundSystem 
{
public:
    map<pair<string,string>,pair<int,int>>mp;
    map<int,pair<string,int>>dp;
    UndergroundSystem() 
    {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        dp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        int travel=t-dp[id].second;
        mp[{dp[id].first,stationName}].first+=travel;
        mp[{dp[id].first,stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        int total_time=mp[{startStation,endStation}].first;
        int person=mp[{startStation,endStation}].second;
        
        return (1.00*total_time)/person;
    }
};
