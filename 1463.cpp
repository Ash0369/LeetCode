//Method-1 : Without Memoization - It will not pass large Test cases


int cp(vector<vector<int>>&grid,int i,int j1,int j2)
{
    if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
    {
        return -1e8;
    }
    if(i==grid.size()-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1]+grid[i][j2];
    }

    
    int nxt_lvl=-1e8;
    for(int a=-1;a<=1;a++)
    {
        for(int b=-1;b<=1;b++)
        {
            int cherry=0;
            if(j1==j2)
            {
                cherry=grid[i][j1];
            }
            else
            {
                cherry=grid[i][j2]+grid[i][j1];
            }
            cherry=cherry+cp(grid,i+1,j1+a,j2+b);
            nxt_lvl=max(nxt_lvl,cherry);
        }
    }
    return nxt_lvl;

}
class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        return cp(grid,0,0,grid[0].size()-1);
    }
};

//Method-2 : Memoization Time Complexity O(r*c*c) and Space Complexity O(r)+O(r*c*c)

int cp(vector<vector<int>>&grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
    {
        return -1e8;
    }
    if(i==grid.size()-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]==-1)
    {
        int nxt_lvl=-1e8;
        for(int a=-1;a<=1;a++)
        {
            for(int b=-1;b<=1;b++)
            {
                int cherry=0;
                if(j1==j2)
                {
                    cherry=grid[i][j1];
                }
                else
                {
                    cherry=grid[i][j2]+grid[i][j1];
                }
                cherry=cherry+cp(grid,i+1,j1+a,j2+b,dp);
                nxt_lvl=max(nxt_lvl,cherry);
            }
        }
        dp[i][j1][j2]=nxt_lvl;
    }
    return dp[i][j1][j2];
}
class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return cp(grid,0,0,grid[0].size()-1,dp);
    }
};


//Method-3 : Tabulation 


class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        for(int j1=0;j1<c;j1++)
        {
            for(int j2=0;j2<c;j2++)
            {
                if(j1==j2)
                {
                    dp[r-1][j1][j2]=grid[r-1][j1];
                }
                else
                {
                    dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
                }
            }
        }
        for(int i=r-2;i>=0;i--)
        {
            for(int j1=0;j1<c;j1++)
            {
                for(int j2=0;j2<c;j2++)
                {
                    int nxt_lvl=-1e8;
                    for(int a=-1;a<=1;a++)
                    {
                        for(int b=-1;b<=1;b++)
                        {
                            int cherry=-1e8;
                            if(j1+a>=0 && j2+b>=0 && j1+a<c && j2+b<c)
                            {
                                if(j1==j2)
                                {
                                    cherry=grid[i][j1];
                                }
                                else
                                {
                                    cherry=grid[i][j2]+grid[i][j1];
                                }
                                cherry=cherry+dp[i+1][j1+a][j2+b];
                            }
                            nxt_lvl=max(nxt_lvl,cherry);
                        }
                    }
                    dp[i][j1][j2]=nxt_lvl;
                }
            }
        }
        return dp[0][0][c-1];
        
    }
};
