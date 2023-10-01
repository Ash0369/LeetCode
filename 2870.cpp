class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            if(x.second==1)
            {
                return -1;
            }
            if(x.second%3==0)
            {
                ans+=x.second/3;
            }
            if(x.second%3==1)
            {
                ans++;
                x.second=x.second-2;
            }
            if(x.second%3==2)
            {
                ans+=(x.second/3);
                ans++;
            }
        }
        return ans;
    }
};
