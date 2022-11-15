#define pii pair<int,pair<int,int>>
class Solution 
{
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        if(grid[0][0]==0)
        {
            pq.push({0,{0,0}});
        }
        else
            pq.push({1,{0,0}});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        while(!pq.empty())
        {
            int already_removed=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==m-1 && y==n-1)
                return already_removed;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && dp[nx][ny]==0)
                {
                    dp[nx][ny]=1;
                    pq.push({already_removed+grid[nx][ny],{nx,ny}});
                }
            }
        }
        return 0;
    }
};
