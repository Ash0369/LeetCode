//Method-1 : 


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


//Method-2 : 


class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int p=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int transaction=n-1;transaction>=0;transaction--)
            {
                if(transaction%3==0)
                {
                    p=dp[index+1][transaction+1]-prices[index];
                }
                else if(transaction>0 && (transaction-1)%3==0)
                {
                    p=dp[index+1][transaction+1]+prices[index];
                }
                else
                {
                    dp[index][transaction]=dp[index+1][transaction+1];
                    continue;
                }
                int np=dp[index+1][transaction];
                
                dp[index][transaction]=max(p,np);
            }
        }
        return dp[0][0];
    }
};


//Method-3 : 

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>dp(n+1,0);
        vector<int>curr(n+1,0);
        int p=0;
        for(int index=n-1;index>=0;index--)
        {
            for(int transaction=n-1;transaction>=0;transaction--)
            {
                if(transaction%3==0)
                {
                    p=dp[transaction+1]-prices[index];
                }
                else if(transaction>0 && (transaction-1)%3==0)
                {
                    p=dp[transaction+1]+prices[index];
                }
                else
                {
                    curr[transaction]=dp[transaction+1];
                    continue;
                }
                int np=dp[transaction];
                
                curr[transaction]=max(p,np);
            }
            dp=curr;
        }
        return dp[0];
    }
};
