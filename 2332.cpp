class Solution 
{
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) 
    {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int n=buses.size();
        int m=passengers.size();
        map<int,bool>mp;
        for(auto x:passengers)
            mp[x]=1;
        
        int i=0;
        int j=0;
        int last_time_to_board=1;
        int seat_left=capacity;
        while(i<n)
        {
            seat_left=capacity;
            while(j<m && seat_left>0 && passengers[j]<=buses[i])
            {
                last_time_to_board=passengers[j];
                j++;
                seat_left--;
            }
            i++;
        }
        
        //Now possiblity are there after boarding of last person also buses are avaliable
        
        if(i!=n)
        {
            //More buses will come
            last_time_to_board=buses[n-1];
        }
        if(seat_left>0)
        {
            //Some seat are left in the last bust
            last_time_to_board=buses[n-1];
        }
        
        //Now we have last time at which we can defenitely get bus.
        //Now if any person came at that time then we have to come before
        
        while(mp[last_time_to_board]==1)
        {
            last_time_to_board--;
        }
        return last_time_to_board;
    }
};
