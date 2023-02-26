class Solution 
{
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n=nums.size();
        map<int,int>mp;
        int target=0;
        for(auto x:nums)
        {
            target=(target+x)%p;
        }
        if(target==0)
        {
            return 0;
        }
        int curr=0;
        int ans=1e9;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            curr=(curr+nums[i])%p;
            int need=(curr-target+p)%p;
            if(mp.find(need)!=mp.end())
            {
                ans=min(ans,i-mp[need]);
            }
            mp[curr]=i;
        }
        if(ans>=n)
        {
            return -1;
        }
        return ans;
    }
};
