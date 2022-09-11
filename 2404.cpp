class Solution 
{
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        map<int,int>mp;
        for(auto x:nums)
        {
            if(x%2==0)
            {
                mp[x]=mp[x]+1;
            }
        }
        int max_value=INT_MIN;
        int ele;
        if(mp.size()==0)
            return -1;
        for(auto x:mp)
        {
            if(x.second>max_value)
            {
                ele=x.first;
                max_value=x.second;
            }
                
        }
        return ele;
    }
};
