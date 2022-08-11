//Method-1 : Time Complexity O(m*n) and Space Complexity O(m*n) + O(m+n)


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

//Method-2 : Tabulation : Time Complexity O(m*n) and Space Complexity O(m*n)

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>vec(m,vector<int>(n,-1));
        vec[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j!=0)
                {
                    vec[i][j]=vec[i][j-1];
                }
                else if(i!=0 && j==0)
                {
                    vec[i][j]=vec[i-1][j];
                }
                else if(i!=0 && j!=0)
                {
                    vec[i][j]=vec[i-1][j]+vec[i][j-1];
                }
            }
        }
        return vec[m-1][n-1];

    }
};
