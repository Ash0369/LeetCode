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


//Method-2 : Tabulation

class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        //B S B S...
        int n=prices.size();
        k=2*k;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int transaction=k-1;transaction>=0;transaction--)
            {
                
                int p=0;
                if(transaction%2==0)
                {
                    p=dp[index+1][transaction+1]-prices[index];
                }
                else
                {
                    p=dp[index+1][transaction+1]+prices[index];
                }
                
                int nt=dp[index+1][transaction];
                dp[index][transaction]=max(p,nt);
            }
        }
        
        return dp[0][0];
    }
};


//Method-3 : Space Optimization

class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        //B S B S...
        int n=prices.size();
        k=2*k;
        vector<int>dp(k+1,0);
        vector<int>curr(k+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int transaction=k-1;transaction>=0;transaction--)
            {
                
                int p=0;
                if(transaction%2==0)
                {
                    p=dp[transaction+1]-prices[index];
                }
                else
                {
                    p=dp[transaction+1]+prices[index];
                }
                
                int nt=dp[transaction];
                curr[transaction]=max(p,nt);
            }
            dp=curr;
        }
        return dp[0];
    }
};
