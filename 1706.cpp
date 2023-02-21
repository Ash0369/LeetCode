class Solution 
{
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            bool res=true;
            int x=0;
            int y=i;
            while(x!=m)
            {
                int val=grid[x][y];
                int nx=x+1;
                if(val==1)
                {
                    int ny=y+1;
                    if(ny==n)
                    {
                        res=false;
                        break;
                    }
                    if(grid[x][ny]==-1)
                    {
                        res=false;
                        break;
                    }
                    x=nx;
                    y=ny;
                }
                else
                {
                    int ny=y-1;
                    
                    if(ny==-1)
                    {
                        res=false;
                        break;
                    }
                    if(grid[x][ny]==1)
                    {
                        res=false;
                        break;
                    }
                    x=nx;
                    y=ny;
                }
            }
            if(res)
            {
                ans.push_back(y);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};
