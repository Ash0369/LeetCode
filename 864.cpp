struct Node
{
    int x;
    int y;
    int key;
};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int n,m;

class Solution 
{
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        int total=0;
        int dp[35][35][65];
        memset(dp,0,sizeof(dp));
        Node start;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    start.x=i;
                    start.y=j;
                    start.key=0;
                }
                if(islower(grid[i][j]))
                {
                    total=total|(1<<(int(grid[i][j])-97));
                }
            }
        }
        
        queue<Node>q;
        q.push(start);
        int ans=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto x=q.front();
                q.pop();
                if(x.key==total)
                {
                    return ans;
                }
                for(int k=0;k<4;k++)
                {
                    int nx=x.x+dx[k];
                    int ny=x.y+dy[k];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!='#')
                    {
                        int c=int(grid[nx][ny]);
                        int new_key=x.key;
                        if(c>=65 && c<=92)
                        {
                            //Lock so we should have key
                            if((x.key&(1<<(c-65)))==0)
                            {
                                continue;
                            }
                        }
                        if(c>=97)
                        {
                            //we can add in key
                            new_key=x.key|(1<<(c-97)); 
                        }
                        if(dp[nx][ny][new_key]==1)
                        {
                            continue;
                        }
                        q.push({nx,ny,new_key});
                        dp[nx][ny][new_key]=1;
                    }
                }
                
            }
            ans++;
        }
        return -1;
    }
};
