//Methd-1 : Memoization

int falling_path(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
{
    if(i==0)
    {
        return matrix[0][j];
    }
    if(dp[i][j]==-1)
    {
        int up=matrix[i][j]+falling_path(matrix,i-1,j,dp);
        int ld=INT_MAX;
        int rd=INT_MAX;
        if(j!=0)
        {
            ld=matrix[i][j]+falling_path(matrix,i-1,j-1,dp);
        }
        if(j!=matrix[0].size()-1)
        {
            rd=matrix[i][j]+falling_path(matrix,i-1,j+1,dp);
        }
        dp[i][j]=min(up,min(ld,rd));
    }
    return dp[i][j];
}
class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=INT_MAX;
        vector<vector<int>>vec(n,vector<int>(m,-1));
        for(int i=0;i<m;i++)
        {
            res=min(res,falling_path(matrix,n-1,i,vec));
        }
        return res;
    }
};

//Method-2 : Tabulation

class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int ld=INT_MAX;
                int rd=INT_MAX;
                if(j!=0)
                {
                    ld=matrix[i][j]+dp[i-1][j-1];
                }
                if(j!=matrix[0].size()-1)
                {
                    rd=matrix[i][j]+dp[i-1][j+1];
                }
                dp[i][j]=min(up,min(ld,rd));
            }
        }
        int res=INT_MAX;
        for(int j=0;j<m;j++)
        {
            res=min(res,dp[n-1][j]);
        }
        return res;
    }
};

//Method-3 : Space Optimization : 

class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>dp(m,-1);
        vector<int>curr(m,-1);
        for(int j=0;j<m;j++)
        {
            dp[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[j];
                int ld=INT_MAX;
                int rd=INT_MAX;
                if(j!=0)
                {
                    ld=matrix[i][j]+dp[j-1];
                }
                if(j!=matrix[0].size()-1)
                {
                    rd=matrix[i][j]+dp[j+1];
                }
                curr[j]=min(up,min(ld,rd));
            }
            dp=curr;
        }
        int res=INT_MAX;
        for(int j=0;j<m;j++)
        {
            res=min(res,dp[j]);
        }
        return res;
    }
};
