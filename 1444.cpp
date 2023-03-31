int mod=1e9+7;
int dp[11][51][51];
int way(vector<string>& pizza, int k,int x,int y)
{
   
    int m=pizza[0].size();
    int n=pizza.size();
    if(x>=m || y>=n)
    {
        return 0;
    }
    if(dp[k][x][y]!=-1)
    {
        return dp[k][x][y];
    }
    if(k==1)
    {
        for(int i=x;i<m;i++)
        {
            for(int j=y;j<n;j++)
            {
                if(pizza[j][i]=='A')
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    
    
    int ans=0;
    bool get=false;
    for(int i=x;i<m;i++)
    {
        for(int j=y;j<n;j++)
        {
            if(get==true || pizza[j][i]=='A')
            {
                get=true;
                ans=(ans+way(pizza,k-1,i+1,y))%mod;
                break;
            }
        }
    }
    get=false;
    for(int j=y;j<n;j++)
    {
        for(int i=x;i<m;i++)
        {
            if(get==true || pizza[j][i]=='A')
            {
                get=true;
                ans=(ans+way(pizza,k-1,x,j+1))%mod;
                break;
            }
        }
    }
    return dp[k][x][y]=ans;
}

class Solution 
{
public:
    int ways(vector<string>& pizza, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return way(pizza,k,0,0);
    }
};
