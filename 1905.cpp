class Solution 
{
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        
        int m=grid2.size();
        int n=grid2[0].size();
        bool dp[m][n];
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=false;
            }
        }
        queue<pair<int,int>>q;
        int counter=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1 && dp[i][j]==false)
                {
                    dp[i][j]=true;
                    q.push({i,j});
                    
                    bool check=true;
                    if(grid1[i][j]==0)
                        check=false;
                    int c=1;
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            
                            if(nx>=0 && ny>=0 && nx<m && ny<n && grid2[nx][ny]==1 && dp[nx][ny]==false)
                            {
                                dp[nx][ny]=true;
                                if(grid1[nx][ny]!=1)
                                {
                                    check=false;
                                }
                                
                                q.push({nx,ny});
                                
                            }
                        }
                    }
                    if(check)
                    {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};
