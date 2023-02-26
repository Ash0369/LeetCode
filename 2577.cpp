#define ll long long
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
#define pii pair<ll int,pair<ll int,ll int>>
class Solution 
{
public:
    int minimumTime(vector<vector<int>>&grid) 
    {
        if(grid[0][1]>1 && grid[1][0]>1)
        {
            return -1;
        }
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,{0,0}});
        vector<vector<bool>>dp(m,vector<bool>(n,false));
        dp[0][0]=0;
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            ll int curr=node.first;
            int x=node.second.first;
            int y=node.second.second;
            if(dp[x][y]==true)
            {
                continue;
            }
            dp[x][y]=true;
            if(x==m-1 && y==n-1)
            {
                return curr;
            }
            for(int i=0;i<4;i++)
            {
                ll int nx=x+dx[i];
                ll int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && dp[nx][ny]==false)
                {
                    if(grid[nx][ny]<=(curr+1) )
                    {
                        pq.push({curr+1,{nx,ny}});
                    }
                    else
                    {
                        int d=grid[nx][ny]-curr;
                        int wait=0;
                        if(d%2==0)
                        {
                            wait++;
                        }
                        pq.push({grid[nx][ny]+wait,{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};
