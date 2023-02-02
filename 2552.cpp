//https://www.youtube.com/watch?v=bTLsE8hGZzc

#define ll long long

class Solution 
{
public:
    long long countQuadruplets(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(4005,vector<int>(n+1,0));
        for(int k=1;k<=n;k++)
        {
            if(nums[0]<=k)
            {
                dp[k][0]=1;
            }
        }
        
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<n;i++)
            {
                if(nums[i]<=k)
                {
                    dp[k][i]=dp[k][i-1]+1;
                }
                else
                {
                    dp[k][i]=dp[k][i-1];
                }
            }
        }
        
        ll int ans=0;
        for(int j=1;j<n;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                if(nums[k]<nums[j])
                {
                    ll int c1=dp[nums[k]-1][j-1];
                    ll int c2=(n-k-1)-(dp[nums[j]][n-1]-dp[nums[j]][k]);
                    ans+=c1*c2;
                }
            }
        }
        
        return ans;
    }
};
