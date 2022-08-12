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
