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


//Method-2 : Binary Search

class MyCalendar 
{
public:
    map<int,int>mp;
    set<pair<int,int>>st;
    MyCalendar() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        auto p=mp.upper_bound(start);
        if(p==mp.end() || end<=p->second)
        {
            mp[end]=start;
            return true;
        }
        return false;
        
    }
};


//Method-3 : Using Hashset

class MyCalendar 
{
public:
    set<pair<int,int>>st;
    MyCalendar() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        auto p=st.lower_bound({start,end});
        if((p!=st.end() && !(end<=p->first) ) || (p!=st.begin() && !(start>=prev(p)->second)))
        {
             return false;
        }
        st.insert({start,end});
        return true;
        
    }
};
