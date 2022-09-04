//Method-1 : Time Complexity is O(n*m) and Space Complexity is O(n*m)+O(n+m)


int longest(string &text1,string &text2,int x1,int x2,vector<vector<int>>&dp)
{
    if(x1<0 || x2<0)
    {
        return 0;
    }
    if(text1[x1]==text2[x2])
    {
       return 1+ longest(text1,text2,x1-1,x2-1,dp);
    }
    else
    {
        if(dp[x1][x2]==-1)
        {
            int a=longest(text1,text2,x1-1,x2,dp);
            int b=longest(text1,text2,x1,x2-1,dp);
            dp[x1][x2]=max(a,b);
        }
        return dp[x1][x2];
    }
}
class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return longest(text1,text2,n1-1,n2-1,dp);
    }
};


//Method-2 : Tabulation, with shifting of index in base case

class Solution 
{
public:
    int longestCommonSubsequence(string text1,string text2) 
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                       dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int a=0;
                    int b=0;
                    a=dp[i-1][j];
                    b=dp[i][j-1];
                    dp[i][j]=max(a,b);
                }
             }
        }
        return dp[n1][n2];
    }
};


//Method-3 : Space Optimization

class Solution 
{
public:
    int longestCommonSubsequence(string text1,string text2) 
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>dp(n2+1,0);
        vector<int>curr(n2+1,0);
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                       curr[j]=1+dp[j-1];
                }
                else
                {
                    int a=dp[j];
                    int b=curr[j-1];
                    curr[j]=max(a,b);
                }
             }
            dp=curr;
        }
        return dp[n2];
    }
};
