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
