bool dp[1000009];
class Solution 
{
public:
    Solution()
    {
        memset(dp,1,sizeof(dp));
        dp[1]=0;
        for(int i=2;i*i<=1000006;i++)
        {
            if(dp[i]==1)
            {
                for(long long int j=1LL*i*i;j<=1000006;j=j+i)
                {
                    dp[j]=0;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) 
    {
        vector<vector<int>>ans;
        for(int i=1;i<=(n/2);i++)
        {
            if(dp[i]==1 && dp[n-i]==1)
            {
                ans.push_back({i,n-i});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
