int dp[105][105];
int game(int index,int m,vector<int>&piles)
{
    if(index==piles.size())
    {
        return 0;
    }
    if(dp[index][m]!=-1)
    {
        return dp[index][m];
    }
    int mx=-1e9;
    int tot=0;
    for(int i=0;i<(2*m);i++)
    {
        if(index+i==piles.size())
        {
            break;
        }
        tot+=piles[i+index];
        mx=max(mx,tot-game(i+index+1,max(m,i+1),piles));
    }
    return dp[index][m]=mx;
}
class Solution 
{
public:
    int stoneGameII(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        int tot=0;
        for(auto x:piles)
        {
            tot=tot+x;
        }
        int val=game(0,1,piles);
        return (tot+val)/2;
    }
};
