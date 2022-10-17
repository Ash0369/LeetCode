//Method-1 : Non DP solution, will  not pass for large test cases.


#define mp(a,b,c) make_pair(make_pair(a,b),c)
void bfs(int x,int y,vector<vector<int>>&visited,vector<vector<int>>& mat,vector<vector<int>>&ans)
{
    visited[x][y]=1;
    queue<pair<pair<int,int>,int>>q;
    q.push(mp(x,y,0));
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    int m=mat.size();
    int n=mat[0].size();
    while(!q.empty())
    {
        int xc=q.front().first.first;
        
        int yc=q.front().first.second;
        int depth=q.front().second;
        
        //cout<<xc<<" "<<yc<<depth<<endl;
        q.pop();
        if(mat[xc][yc]==0)
        {
           // cout<<xc<<" "<<yc<<endl;
            ans[x][y]=depth;
            break;
        }
        
        for(int j=0;j<4;j++)
        {
            int nxc=xc+dx[j];
            int nyc=yc+dy[j];
            
            if(nxc>=0 && nxc<m && nyc>=0 && nyc<n && visited[nxc][nyc]==false)
            {
                visited[nxc][nyc]=true;
                q.push(mp(nxc,nyc,depth+1));
            }
        }
    }
}
class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<vector<int>>visited(m,vector<int>(n,0));
                bfs(i,j,visited,mat,ans);
                
            }
        }
        return ans;
    }
};
