int counter=0;
int  count_paths(int x,int y,vector<vector<int>>&vec)
{
    if(x<0 || y<0)
    {
        return 0;
    }
    if(x==0 && y==0)
    {
        return 1;
    }
    if(vec[x][y]==-1)
    {
        int a=count_paths(x-1,y,vec);
        int b=count_paths(x,y-1,vec);
        vec[x][y]=a+b;
    }
    return vec[x][y];
}
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>vec(m,vector<int>(n,-1));
        return count_paths(m-1,n-1,vec);
    }
};
