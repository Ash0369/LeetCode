//Method-1 : 

class Solution 
{
public:
    int minimumRounds(vector<int>& tasks) 
    {
        map<int,int>mp;
        for(auto x:tasks)
            mp[x]++;
        int round=0;
        for(auto x:mp)
        {
            int ele=x.second;
            while(ele%3!=0 && ele>=2)
            {
                ele=ele-2;
                round++;
            }
            if(ele%3!=0)
                return -1;
            round+=(ele/3);
            ele=ele/3;
        }
        return round;
    }
};

//Method-2 : 

class Solution 
{
public:
    int minimumRounds(vector<int>& tasks) 
    {
        map<int,int>mp;
        for(auto x:tasks)
            mp[x]++;
        int round=0;
        for(auto x:mp)
        {
            int ele=x.second;
            if(ele<2)
                return -1;
            if(ele%3==0)
                round+=ele/3;
            else
                round+=(ele/3)+1;
        }
        return round;
    }
};
