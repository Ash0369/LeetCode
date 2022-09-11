//Mehod-1 : Memoization


int distinct(int i,int j,string &s,string &t,vector<vector<int>>&dp)
{
    if(j<0)
        return 1;
    if(i<0)
        return 0;
    
    if(dp[i][j]==-1)
    {
        if(s[i]==t[j])
        {
            int a=distinct(i-1,j-1,s,t,dp);
            int b=distinct(i-1,j,s,t,dp);
            dp[i][j]=a+b;
        }
        else
        {
            dp[i][j]=distinct(i-1,j,s,t,dp);
        }
    }
    return dp[i][j];
}
class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return distinct(m-1,n-1,s,t,dp);
    }
};
