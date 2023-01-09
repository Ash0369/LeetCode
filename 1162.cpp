class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({0,{i,j}});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int ans=-1;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int x=node.second.first;
            int y=node.second.second;
            int d=node.first;
            
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && dp[nx][ny]==0)
                {
                    dp[nx][ny]=d+1;
                    ans=d+1;
                    q.push({d+1,{nx,ny}});
                }
            }
        }
        return ans;
    }
};
