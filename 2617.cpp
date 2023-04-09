class Solution 
{
public:
    int minimumVisitedCells(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1)
        {
            return 1;
        }
        queue<pair<int,int>>q;
        int step=1;
        q.push({0,0});
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=1;i<=grid[x][y];i++)
                {
                    if(x+i<m && dp[x+i][y]==-1)
                    {
                        dp[x+i][y]=1;
                        if(x+i==m-1 && y==n-1)
                        {
                            return step+1;
                        }
                        q.push({x+i,y});
                    }
                    if(y+i<n && dp[x][y+i]==-1)
                    {
                        dp[x][y+i]=1;
                        if(y+i==n-1 && x==m-1)
                        {
                            return step+1;
                        }
                        q.push({x,y+i});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
