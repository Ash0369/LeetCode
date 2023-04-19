//Method-1 : 

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
        vector<int>row(m+1,0);
        vector<int>col(n+1,0);
        row[0]=0;
        col[0]=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int start=max(row[x],y);
                for(int i=start+1;i<=min(n-1,grid[x][y]+y);i++)
                {
                    if(i<n && dp[x][i]==-1)
                    {
                        dp[x][i]=1;
                        if(i==n-1 && x==m-1)
                        {
                            return step+1;
                        }
                        q.push({x,i});
                    }
                    if(i==(row[x]+1))
                    row[x]=i;
                }
                start=max(x,col[y]);
                for(int i=start+1;i<=min(m-1,grid[x][y]+x);i++)
                {
                    if(i<m && dp[i][y]==-1)
                    {
                        dp[i][y]=1;
                        if(i==m-1 && y==n-1)
                        {
                            return step+1;
                        }
                        q.push({i,y});
                    }
                    if(i==(col[y]+1))
                    col[y]=i;
                }
            }
            step++;
        }
        return -1;
    }
};
