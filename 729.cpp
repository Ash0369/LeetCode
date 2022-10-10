//Method-1 : Brute Force


class MyCalendar 
{
public:
    map<int,int>mp;
    MyCalendar() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        for(auto x:mp)
        {
            if(!(x.second<=start || x.first>=end))
            {
                return false;
            }
        }
        mp[start]=end;
        return true;
    }
};
