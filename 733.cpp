//Method-1 : BFS


#define mp(a,b) make_pair(a,b)
class Solution 
{
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push(mp(sr,sc));
        vector<vector<int>>visited(60,vector<int>(60,0));
        int intial_color=image[sr][sc];
        visited[sr][sc]=1;
        while(!q.empty())
        {
            auto x=q.front().first;
            auto y=q.front().second;
            q.pop();
            if(image[x][y]==intial_color)
            {
                image[x][y]=color;
                
                if(x>0 && visited[x-1][y]==0)
                {
                    visited[x-1][y]=1;
                    q.push(mp(x-1,y));
                }
                if(y>0 && visited[x][y-1]==0)
                {
                    visited[x][y-1]=1;
                    q.push(mp(x,y-1));
                }
                if(x<m-1 && visited[x+1][y]==0)
                {
                    visited[x+1][y]=1;
                    q.push(mp(x+1,y));
                }
                if(y<n-1 && visited[x][y+1]==0)
                {
                    visited[x][y+1]=1;
                    q.push(mp(x,y+1));
                }
            }
        }
        return image;
    }
};


//Method-2 : DFS


vector<int>delx={-1,0,1,0};
vector<int>dely={0,1,0,-1};
void dfs(vector<vector<int>>& image,int x,int y,int color,vector<vector<int>>&visited,int intial_color)
{
    int m=image.size();
    int n=image[0].size();
    
    image[x][y]=color;
    
    for(int i=0;i<4;i++)
    {
        if(x+delx[i]>=0 && x+delx[i]<m && y+dely[i]>=0 && y+dely[i]<n)
        {
            if(visited[x+delx[i]][y+dely[i]]==0 && image[x+delx[i]][y+dely[i]]==intial_color)
            {
                visited[x+delx[i]][y+dely[i]]=1;
                dfs(image,x+delx[i],y+dely[i],color,visited,intial_color);
            }
        }
        
    }
}
class Solution 
{
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size();
        int n=image[0].size();
        
        vector<vector<int>>visited(60,vector<int>(60,0));
        int intial_color=image[sr][sc];
        visited[sr][sc]=1;
        dfs(image,sr,sc,color,visited,intial_color);
        return image;
    }
};
