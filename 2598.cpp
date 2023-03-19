//Method-1 : 


class Solution 
{
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            int rem=abs(x)%value;
            if(x<0 && rem!=0)
            {
                rem=value-rem;
            }
            mp[rem]++;
        }
        int i=0;
        if(mp[0]>1)
        {
            mp[value]++;
        }
        while(true)
        {
            if(mp[i%value]==0)
            {
                return i;
            }
            mp[i%value]--;
            i++;
        }
        return -1;
    }
};

//Method-2 : 


class Solution 
{
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            int rem=(value+(x%value))%value;
            mp[rem]++;
        }
        int i=0;
        if(mp[0]>1)
        {
            mp[value]++;
        }
        while(true)
        {
            if(mp[i%value]==0)
            {
                return i;
            }
            mp[i%value]--;
            i++;
        }
        return -1;
    }
};
