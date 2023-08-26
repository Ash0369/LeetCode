class Solution 
{
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
      
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<n;i++)
        {
            int c=pairs[i][0];
            int d=pairs[i][1];
            for(int b=0;b<i;b++)
            {
                int end=pairs[b][1];
                dp[i][b]=max(dp[i][b],dp[i-1][b]);
                if(c>end)
                {
                    dp[i][i]=max(dp[i][i],1+dp[i-1][b]);
                }
            }
            dp[i][i]=max(dp[i][i],1);
        }
        int ans=0;
        for(int b=0;b<n;b++)
        {
            ans=max(ans,dp[n-1][b]);
        }
        return ans;
    }
};
