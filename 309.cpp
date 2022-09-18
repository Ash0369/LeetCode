int mprofit(vector<int>&profit,int index,int transaction,vector<vector<int>>&dp)
{
    int p=0;
    if(index==profit.size())
        return 0;
    if(dp[index][transaction]==-1)
    {
        if(transaction%3==0)
        {
            p=mprofit(profit,index+1,transaction+1,dp)-profit[index];
        }
        else if(transaction>0 && (transaction-1)%3==0)
        {
            p=mprofit(profit,index+1,transaction+1,dp)+profit[index];
        }
        else
        {
            dp[index][transaction]=mprofit(profit,index+1,transaction+1,dp);
            return dp[index][transaction];
        }
        int np=mprofit(profit,index+1,transaction,dp);
        
        dp[index][transaction]=max(p,np);
    }
    return dp[index][transaction];
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return mprofit(prices,0,0,dp);
    }
};
