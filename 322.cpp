//Method-1 : Memoization  , Time Complexity O(n*target) , Space Complexity O(n*target)+O(target)


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

//Method-2 : Tabulation


class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e8));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }
        }
        

        for(int index=1;index<n;index++)
        {
            for(int a=1;a<=amount;a++)
            {
                int not_pick=0+dp[index-1][a];
                int pick_up=INT_MAX;
                if(a>=coins[index])
                {
                    pick_up=1+dp[index][a-coins[index]];
                }
                dp[index][a]=min(pick_up,not_pick);
            }
        }
        if(dp[n-1][amount]==1e8)
        {
            return -1;
        }
        return dp[n-1][amount];
    }
};

//Method-3 : Space Optimzation 


class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<int>dp(amount+1,1e8);
        vector<int>curr(amount+1,1e8);
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[i]=i/coins[0];
            }
        }
        
        for(int index=1;index<n;index++)
        {
            for(int a=0;a<=amount;a++)
            {
                int not_pick=0+dp[a];
                int pick_up=INT_MAX;
                if(a>=coins[index])
                {
                    pick_up=1+curr[a-coins[index]];
                }
                curr[a]=min(pick_up,not_pick);
            }
            dp=curr;
        }
        if(dp[amount]==1e8)
        {
            return -1;
        }
        return dp[amount];
    }
};
