//Method-1 : 

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


//Method-2 : Reducing Loop count from 2 to 1


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
            
            if(board[i][0]=='O')
            {
                q.push(mp(i,0));
                vis[i][0]=true;
            }
            if(board[i][n-1]=='O')
            {
                q.push(mp(i,n-1));
                vis[i][n-1]=true;
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(board[0][i]=='O')
            {
                q.push(mp(0,i));
                vis[0][i]=true;
            }
            if(board[m-1][i]=='O')
            {
                q.push(mp(m-1,i));
                vis[m-1][i]=true;
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
