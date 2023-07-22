int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
double dp[30][30][101];
double dfs(int n,int k,int r,int c)
{
    if(r>=n || r<0 || c>=n || c<0)
    {
        return 0;
    }
    if(k==0)
    {
        return 1;
    }
    if(abs(3-dp[r][c][k])>1)
    {
         //cout<<abs(dp[r][c])<<endl;
        return dp[r][c][k];
    }
   
    //Try all 8 directions
    double ans=0;
    for(int i=0;i<8;i++)
    {
        ans+=dfs(n,k-1,r+dx[i],c+dy[i]);
    }
    return dp[r][c][k]=ans/8;
}
class Solution 
{
public:
    double knightProbability(int n, int k, int row, int column) 
    {
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<30;j++)
            {
                for(int a=0;a<=100;a++)
                {
                    dp[i][j][a]=3.0;
                }
               
            }
        }
        return dfs(n,k,row,column);
    }
};
