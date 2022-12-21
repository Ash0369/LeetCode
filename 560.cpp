class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        map<int,int>mp;
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==k)
            {
                ans++;
            }
            if(mp.find(dp[i]-k)!=mp.end())
            {
                ans+=mp[dp[i]-k];
            }
            mp[dp[i]]++;
        }
        return ans;
    }
};
