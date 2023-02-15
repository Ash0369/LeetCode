int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int m;
int n;
bool dfsa(int x,int y,vector<vector<int>>&heights,vector<vector<bool>>&dp)
{
    if(y==n-1 || x==m-1)
    {
        return true;
    }
    dp[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n && heights[nx][ny]<=heights[x][y] && dp[nx][ny]==false)
        {
            if(dfsa(nx,ny,heights,dp))
            {
                dp[x][y]=false;
                return true;
            }
        }
    }
    dp[x][y]=false;
    return false;
}

bool dfsp(int x,int y,vector<vector<int>>& heights,vector<vector<bool>>&dp)
{ 
    if(y==0 || x==0)
    {
        return true;
    }
    dp[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n && heights[nx][ny]<=heights[x][y] && dp[nx][ny]==false)
        {
            if(dfsp(nx,ny,heights,dp))
            {
                dp[x][y]=false;
                return true;
            }
        }
    }
    dp[x][y]=false;
    return false;
}

class Solution 
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>>ans;
        m=heights.size();
        n=heights[0].size();
        vector<vector<bool>>dp1(m,vector<bool>(n,false));
        vector<vector<bool>>dp2(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool a=dfsa(i,j,heights,dp1);
                bool b=dfsp(i,j,heights,dp2);
                if(a==true && b==true)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
