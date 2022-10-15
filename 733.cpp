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
