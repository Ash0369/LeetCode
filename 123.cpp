//Method-1 : 

int res=0;
int profit(vector<int>&prices,int hold,int index,int transaction,vector<vector<vector<int>>>&dp)
{
    int pr=0;
    if(index==prices.size())
        return 0;
    
    if(dp[index][hold][transaction]==-1)
    {
        if(hold==0 && transaction<2)
        {
            pr=profit(prices,1,index+1,transaction+1,dp)-prices[index];
        }
        else if(hold==1)
        {
            pr=profit(prices,0,index+1,transaction,dp)+prices[index];
            
        }
        int npr=profit(prices,hold,index+1,transaction,dp);
        if(transaction==2)
        {
            res=max(res,max(pr,npr));
        }
        dp[index][hold][transaction]=max(pr,npr);
    }
    return dp[index][hold][transaction];
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        res=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return profit(prices,0,0,0,dp);
    }
};
