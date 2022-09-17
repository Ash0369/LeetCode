//Method-1 : 

int maxp(vector<int>&prices,int index,int status,vector<vector<int>>&dp)
{
    if(index==prices.size())
    {
        return 0;
    }
    if(dp[index][status]==-1)
    {
        int a=0;
        int b=0;
        if(status==0)
        {
            a=-1*prices[index]+maxp(prices,index+1,1,dp);
        }
        else if(status==1)
        {
            a=prices[index]+maxp(prices,index+1,0,dp);
        }
        b=maxp(prices,index+1,status,dp);
        
        dp[index][status]=max(a,b);
    }
    return  dp[index][status];
    
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return maxp(prices,0,0,dp);
    }
};

//Method-2 :

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        dp[n][1]=0;
        dp[n][0]=0;
        
        for(int index=n-1;index>=0;index--)
        {
            for(int status=0;status<=1;status++)
            {
                int a=0;
                int b=0;
                if(status==0)
                {
                    a=-1*prices[index]+dp[index+1][1];
                }
                else if(status==1)
                {
                    a=prices[index]+dp[index+1][0];
                }
                b=dp[index+1][status];
                dp[index][status]=max(a,b);
            }
        }
         return dp[0][0];
        
    }
};
