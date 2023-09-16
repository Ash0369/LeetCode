class Solution 
{
public:
    int minLengthAfterRemovals(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        int f=-1;
        for(auto x:mp)
        {
            if(x.second>(n/2))
            {
                f=x.second;
            }
        }
        if(f==-1)
        {
            if(n%2)
            {
                return 1;
            }
            return 0;
        }
        return f-(n-f);
    }
};
