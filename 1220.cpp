int mod=1000000007;
class Solution 
{
public:
    int countVowelPermutation(int n) 
    {
        long long int dp[n][6];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<5;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++)
        {
            dp[i][0]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
            dp[i][3]=(dp[i-1][2])%mod;
            dp[i][4]=(dp[i-1][2]+dp[i-1][3])%mod;
        }
        return (dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4])%mod;
    }
};
