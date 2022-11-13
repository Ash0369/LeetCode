class Solution 
{
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        pq.push({grid[0][0],{0,0}});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        dp[0][0]=grid[0][0];
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            int x=node.second.first;
            int y=node.second.second;
            if(x==n-1 && y==n-1)
                return node.first;
            int time=node.first;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n)
                {
                    int dist=max(grid[nx][ny],time);
                    if(dp[nx][ny]>dist)
                    {
                        pq.push({dist,{nx,ny}});
                        dp[nx][ny]=dist;
                    }
                }
            }
            
        }
        return 0;
    }
};
