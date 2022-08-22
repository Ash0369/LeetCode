int count(vector<int>&coins,int amount,int index,vector<vector<int>>&dp)
{
    if(amount==0)
    {
        return 1;
    }
    if(index==0)
    {
        if(amount%coins[0]==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[index][amount]==-1)
    {
        int not_pick=count(coins,amount,index-1,dp);
        int pick=0;
        if(amount>=coins[index])
        {
            pick=count(coins,amount-coins[index],index,dp);
        }
        dp[index][amount]=not_pick+pick;
    }
    return dp[index][amount];

}
class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return count(coins,amount,coins.size()-1,dp);
    }
};
