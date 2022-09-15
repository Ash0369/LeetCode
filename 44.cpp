//Method-1 : Memoization

bool match(string &s,string &p,int i,int j,vector<vector<int>>&dp)
{
    if(i<0 && j<0)
        return true;
    
    if(j<0  && i>=0)
        return false;
    if(i<0)
    {
        for(int index=j;index>=0;index--)
        {
            if(p[index]!='*')
                return false;
        }
        return true;
    }
    
    if(dp[i][j]==-1)
    {
        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=match(s,p,i-1,j-1,dp);
        }
        if(p[j]=='*')
        {
            return dp[i][j]= match(s,p,i,j-1,dp) | match(s,p,i-1,j,dp); //considered star means nothing then matched start with that position but not moved star pointer.
        }
    
        return dp[i][j]=false;
    }
    return dp[i][j];
}
class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m=s.length();
        int n=p.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return match(s,p,m-1,n-1,dp);
    }
};

//Method-2 : Tabulation 

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m=s.length();
        int n=p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,true));
        
        //1st base case
        dp[0][0]=true;
        
        //2nd base case
        for(int i=1;i<=m;i++)
            dp[i][0]=false;
        
        //3rd base case
        
        for(int j=1;j<=n;j++)
        {
            bool flag=true;
            for(int index=j;index>0;index--)
            {
                if(p[index-1]!='*')
                {
                    flag=false;
                    break;
                }
                    
            }
            dp[0][j]=flag;
        }
        
        //Changing parameters
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]= dp[i][j-1] | dp[i-1][j]; 
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};
