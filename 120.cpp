//Method-1 : Memoization

int minpath(vector<vector<int>>&triangle,int x,int y,vector<vector<int>>&dp)
{
    if(x==triangle.size()-1)
    {
        return triangle[x][y];
    }
    if(dp[x][y]==-1)
    {
        int a=triangle[x][y]+minpath(triangle,x+1,y,dp);
        int b=triangle[x][y]+minpath(triangle,x+1,y+1,dp);
        dp[x][y]=min(a,b);
    }
    return dp[x][y];
}
class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>>dp(triangle.size(),vector<int>(201,-1));
        return minpath(triangle,0,0,dp);
    }
};

//Method-2 : Tabuation

class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>>dp(triangle.size(),vector<int>(201,-1));
        int n= triangle.size();
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};


//Method-3 : Space Optimization : 


class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int>dp(triangle.size(),-1);
        vector<int>curr(triangle.size(),-1);
        int n= triangle.size();
        for(int j=0;j<n;j++)
        {
            dp[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=triangle[i][j]+dp[j];
                int diag=triangle[i][j]+dp[j+1];
                curr[j]=min(down,diag);
            }
            dp=curr;
                
        }
        return dp[0];
    }
};
