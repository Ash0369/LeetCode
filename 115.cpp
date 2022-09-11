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


//Method-2 : Tabulation

#define ll unsigned long long
class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<ll int>>dp(m+1,vector<ll int>(n+1,0));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=0; //We can remove this also as everything is intialized with 0 , but to show proper conversion of all base cases of recursion we have kept it.
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];  
    }
};


//Method-3 : Tabulation(Countering overflow)

class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<double>>dp(m+1,vector<double>(n+1,0));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=0; //We can remove this also as everything is intialized with 0 , but to show proper conversion of all base cases of recursion we have kept it.
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];  
    }
};

//Method-4 : Space Optimization


class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<double>dp(n+1,0);
        vector<double>curr(n+1,0);
          
        for(int j=1;j<=n;j++)
        {
            curr[j]=0;
            dp[j]=0;
        }
        dp[0]=1;
        curr[0]=1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=dp[j-1]+dp[j];
                }
                else
                {
                    curr[j]=dp[j];
                    dp[j]=dp[j];
                }
            }
            dp=curr;
        }
        return (int)dp[n];  
    }
};
