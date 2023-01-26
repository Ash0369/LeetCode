double dist(int x,int y,int nx,int ny)
{
    double a=pow(x-nx,2);
    double b=pow(y-ny,2);
    return pow(a+b,0.5);
}
int count(int index,vector<bool>&dp,vector<vector<int>>& bombs)
{
    int ans=1;
    dp[index]=true;
    int n=bombs.size();
    int x=bombs[index][0];
    int y=bombs[index][1];
    int r=bombs[index][2];
    for(int i=0;i<n;i++)
    {
        if(i==index || dp[i]==true)
            continue;
        
        int nx=bombs[i][0];
        int ny=bombs[i][1];
        
        double d=dist(x,y,nx,ny);
        
        if(d<=r)
        {
            ans+=count(i,dp,bombs);
        }
    }
    return ans;
}
class Solution 
{
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int ans=0;
        int n=bombs.size();
        for(int i=0;i<n;i++)
        {
            vector<bool>dp(n,false);
            int temp=count(i,dp,bombs);
            ans=max(ans,temp);
        }
        return ans;
    }
};
