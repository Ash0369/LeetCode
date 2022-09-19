//Method-1 : 

int profit(vector<int>& prices,int &fee,int index,int hold,vector<vector<int>>&dp)
{
    if(index==prices.size())
        return 0;
    
    if(dp[index][hold]==-1)
    {
        int p=0;
        if(hold==0)
        {
            p=profit(prices,fee,index+1,1,dp)-prices[index];
        }
        else if(hold==1)
        {
            p=profit(prices,fee,index+1,0,dp)+prices[index]-fee;
        }
        int q=profit(prices,fee,index+1,hold,dp);
        
        dp[index][hold]=max(p,q);
    }
    return dp[index][hold];
    
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return profit(prices,fee,0,0,dp);
    }
};

//Method-2 : 

int profit(vector<int>& prices,int &fee,int index,int hold,vector<vector<int>>&dp)
{
    if(index==prices.size())
        return 0;
    
    if(dp[index][hold]==-1)
    {
        int p=0;
        if(hold==0)
        {
            p=profit(prices,fee,index+1,1,dp)-prices[index];
        }
        else if(hold==1)
        {
            p=profit(prices,fee,index+1,0,dp)+prices[index]-fee;
        }
        int q=profit(prices,fee,index+1,hold,dp);
        
        dp[index][hold]=max(p,q);
    }
    return dp[index][hold];
    
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int hold=1;hold>=0;hold--)
            {
                int p=0;
                if(hold==0)
                {
                    p=dp[index+1][1]-prices[index];
                }
                else if(hold==1)
                {
                    p=dp[index+1][0]+prices[index]-fee;
                }
                int q=dp[index+1][hold];
                
                dp[index][hold]=max(p,q);
            }
        }
        return dp[0][0];
        
    }
};

//Method-3 : 

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        vector<int>dp(2,0);
        vector<int>curr(2,0);
        
        for(int index=n-1;index>=0;index--)
        {
            for(int hold=1;hold>=0;hold--)
            {
                int p=0;
                if(hold==0)
                {
                    p=dp[1]-prices[index];
                }
                else if(hold==1)
                {
                    p=dp[0]+prices[index]-fee;
                }
                int q=dp[hold];
                
                curr[hold]=max(p,q);
            }
            dp=curr;
        }
        return dp[0];
    }
};
