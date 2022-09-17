//Method-1 : 

int maxp(vector<int>&prices,int index,int status,vector<vector<int>>&dp)
{
    if(index==prices.size()-1)
    {
        if(status==1)
            return prices[index];
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
