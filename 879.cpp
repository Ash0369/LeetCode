int mod=1e9+7;
int dp[101][101][105];
class Solution 
{
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        int mp=minProfit;
        memset(dp,0,sizeof(dp));
        int total=0;
        for(int i=0;i<=n;i++)
        {
            dp[group.size()][i][minProfit]=1;
        }
        int ans=0;
        for(int i=profit.size()-1;i>=0;i--)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=mp;k++)
                {
                    dp[i][j][k]=dp[i+1][j][k];
                    if(j+group[i]<=n)
                    {
                        dp[i][j][k]=(dp[i][j][k]+dp[i+1][j+group[i]][min(mp,k+profit[i])])%mod;
                    }
                    
                }
            }
        }
        return dp[0][0][0];
    }
};
