//Method-1 : Brute Force

#define mp(a,b) make_pair(a,b)
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+2,vector<int>(n+2,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 
                if(dp[i][j]==0 && grid[i][j]=='1')
                {
                    cnt++;
                    dp[i][j]=1;
                    queue<pair<int,int>>q;
                    q.push(mp(i,j));
                    while(!q.empty())
                    {
                        auto a=q.front();
                        q.pop();
                        int x=a.first;
                        int y=a.second;
                        
                        if(x>0 && grid[x-1][y]=='1' && dp[x-1][y]==0)
                        {
                            dp[x-1][y]=1;
                            q.push(mp(x-1,y));
                        }
                        if(y>0 && grid[x][y-1]=='1' && dp[x][y-1]==0)
                        {
                            dp[x][y-1]=1;
                            q.push(mp(x,y-1));
                        }
                        if(y<n-1 && grid[x][y+1]=='1' && dp[x][y+1]==0)
                        {
                            dp[x][y+1]=1;
                            q.push(mp(x,y+1));
                        }
                        if(x<m-1 && grid[x+1][y]=='1' && dp[x+1][y]==0)
                        {
                            dp[x+1][y]=1;
                            q.push(mp(x+1,y));
                        }
                       
                    }
                }
            }
        }
        return cnt;
    }
};
