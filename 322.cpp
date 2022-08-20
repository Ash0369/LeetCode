int coin(vector<int>&coins,int amount,int index,vector<vector<int>>&dp)
{
    if(amount==0)
    {
        return 0;
    }
    if(index==0)
    {
        if(amount%coins[0]==0)
        {
            return amount/coins[0];
        }
        else
        {
            return 1e8;
        }
    }

    if(dp[index][amount]==-1)
    {
        int not_pick=0+coin(coins,amount,index-1,dp);
        //If pick up then we have many option either 1 piece of that denomination or 2     or more..
        int pick_up=INT_MAX;
        if(amount>=coins[index])
        {
            pick_up=1+coin(coins,amount-coins[index],index,dp);
        }
        dp[index][amount]=min(pick_up,not_pick);
    }

    return dp[index][amount];
}
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=coin(coins,amount,coins.size()-1,dp);
        if(ans!=1e8)
        {
            return ans;
        }
        return -1;
    }
};
