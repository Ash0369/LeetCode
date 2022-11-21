class Solution
{
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        int m=maze.size();
        int n=maze[0].size();
        vector<int>dp(m*n+5,0);
        int x=entrance[0];
        int y=entrance[1];
        dp[(x*n)+y]=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int k=0;
        while(!q.empty())
        {
            k++;
            int sz=q.size();
            for(int j=0;j<sz;j++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
            
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
            
                    if(nx>=0 && ny>=0 && nx<m && ny<n && maze[nx][ny]=='.')
                    {
                        if(dp[(nx*n)+ny]==0)
                        {
                            dp[(nx*n)+ny]=1;
                            q.push({nx,ny});
                    
                            if(nx==0 || ny==0 || nx==m-1 || ny==n-1)
                               return k;
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};
