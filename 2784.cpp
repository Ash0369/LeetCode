class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n=nums.size();
        n--;
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        if(mp[n]!=2)
        {
            return false;
        }
        for(int i=1;i<n;i++)
        {
            if(mp[i]!=1)
            {
                return false;
            }
        }
        return true;
    }
};
