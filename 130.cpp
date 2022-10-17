#define mp(a,b) make_pair(a,b)
class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && (i==0 || j==0 || i==m-1 || j==n-1))
                {
                    q.push(mp(i,j));
                    vis[i][j]=true;
                }
            }
        }
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int j=0;j<4;j++)
            {
                int nx=x+dx[j];
                int ny=y+dy[j];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n)
                {
                    if(board[nx][ny]=='O' && vis[nx][ny]==false)
                    {
                        q.push(mp(nx,ny));
                        vis[nx][ny]=true;
                    }
                }       
            }  
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==false)
                    board[i][j]='X';
            }
        }
        
    }
};
