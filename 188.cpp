//Method-1 : Memoization

int sell (int k,vector<int>&prices,int transaction,int index,vector<vector<int>>&dp)
{
    if(transaction==k || index==prices.size())
        return 0;
    if(dp[index][transaction]==-1)
    {
        int p=0;
        if(transaction%2==0)
        {
            p=sell(k,prices,transaction+1,index+1,dp)-prices[index];
        }
        else
        {
            p=sell(k,prices,transaction+1,index+1,dp)+prices[index];
        }
        
        int nt=sell(k,prices,transaction,index+1,dp);
        dp[index][transaction]=max(p,nt);
    }
    return dp[index][transaction];
}
class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        //B S B S...
        int n=prices.size();
        k=2*k;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return sell(k,prices,0,0,dp);
    }
};
