//Method-1 : Memoization


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


//Method-2 : Tabulation

class Solution 
{
public:
    int change(int amount, vector<int>&coins) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++) //1st base case of recursion
        {
            dp[i][0]=1;
        }
        for(int j=amount;j>0;j--)
        {
            if(j%coins[0]==0)
            {
                dp[0][j]=1;
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int not_pick=dp[i-1][j];
                int pick=0;
                if(j>=coins[i])
                {
                    pick=dp[i][j-coins[i]];
                }
                dp[i][j]=not_pick+pick;
            }
        }
        return dp[n-1][amount];
    }
};
