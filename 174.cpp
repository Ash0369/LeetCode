//Method-1 : 

#define ll long long

class Solution 
{
public:
    int dp[205][205];
    ll int game(vector<vector<int>>& dungeon,int x,int y,int m,int n)
    {
        if(x>=m || y>=n)
            return INT_MAX;
        if(x==m-1 && y==n-1)
        {
             if(dungeon[x][y]<=0)
             {
                 return abs(dungeon[x][y])+1;
             }
            return 1;
        }
        if(dp[x][y]==-1)
        {
            int left=game(dungeon,x+1,y,m,n);
            int up=game(dungeon,x,y+1,m,n);
            
            ll int k=min(left,up)-dungeon[x][y];
            if(k<=0)
                dp[x][y]=1;
            else
                dp[x][y]=k;
        }
        return dp[x][y];
        
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m=dungeon.size();
        int n=dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        return game(dungeon,0,0,m,n);
      
    }
};


//Merthod-2 : 


class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1]=1;
        dp[m-1][n]=1;  
        for(int x=m-1;x>=0;x--)
        {
            for(int y=n-1;y>=0;y--)
            {
                int left=dp[x+1][y];
                int up=dp[x][y+1];
                dp[x][y]=max(1,min(left,up)-dungeon[x][y]);
            }
        }
        return dp[0][0];
    }
};
