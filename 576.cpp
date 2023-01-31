//Method-1 :

int mod=1e9+7;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int path(int m,int n,int move,int row,int col,vector<vector<vector<int>>>&dp)
{
    if(move==0)
        return 0;
    int ans=0;
    if(dp[row][col][move]!=-1)
        return dp[row][col][move];
    for(int i=0;i<4;i++)
    {
        int nx=row+dx[i];
        int ny=col+dy[i];
        
        if(nx>=0 && ny>=0 && nx<m && ny<n)
        {
            //Next position inside 
            ans=(ans+path(m,n,move-1,nx,ny,dp))%mod;
        }
        else
        {
            ans=(ans+1)%mod;
        }
    }
    return dp[row][col][move]=ans;
}
class Solution 
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return path(m,n,maxMove,startRow,startColumn,dp);
    }
};
