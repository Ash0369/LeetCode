int m,n;
void dfs(int x,int y,vector<vector<int>>&land,int &lastx,int &lasty)
{
    land[x][y]=0;
    if(x>=lastx)
    {
        lastx=x;
        lasty=max(lasty,y);
    }
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n && land[nx][ny]==1)
        {
            dfs(nx,ny,land,lastx,lasty);
        }
    }
}
class Solution 
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        m=land.size();
        n=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i][j]==1)
                {
                    
                    int x=i;
                    int y=j;
                    dfs(i,j,land,x,y);
                    ans.push_back({i,j,x,y});
                }
            }
        }
        return ans;
    }
};
