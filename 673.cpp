class Solution 
{
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,1),cnt(n,1); 
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    if(1+dp[prev]>dp[i])
                    {
                        dp[i]=1+dp[prev];
                        cnt[i]=cnt[prev];
                    }
                    else if(1+dp[prev]==dp[i])
                    {
                        cnt[i]=cnt[i]+cnt[prev];
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==ans)
                c=c+cnt[i];
        }
        return c;
    }
};
