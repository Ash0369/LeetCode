//Method-1 : Memoization

int res=0;
int profit(vector<int>&prices,int hold,int index,int transaction,vector<vector<vector<int>>>&dp)
{
    int pr=0;
    if(index==prices.size())
        return 0;
    
    if(dp[index][hold][transaction]==-1)
    {
        if(hold==0 && transaction<2)
        {
            pr=profit(prices,1,index+1,transaction+1,dp)-prices[index];
        }
        else if(hold==1)
        {
            pr=profit(prices,0,index+1,transaction,dp)+prices[index];
            
        }
        int npr=profit(prices,hold,index+1,transaction,dp);
        if(transaction==2)
        {
            res=max(res,max(pr,npr));
        }
        dp[index][hold][transaction]=max(pr,npr);
    }
    return dp[index][hold][transaction];
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        res=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return profit(prices,0,0,0,dp);
    }
};

//Method-2 : Optimized Memoization

int res=0;
int profit(vector<int>&prices,int hold,int index,int transaction,vector<vector<vector<int>>>&dp)
{
    int pr=0;
    if(index==prices.size())
        return 0;
    
    if(dp[index][hold][transaction]==-1)
    {
        if(hold==0 && transaction<2)
        {
            pr=profit(prices,1,index+1,transaction+1,dp)-prices[index];
        }
        else if(hold==1)
        {
            if(transaction==2)
            {
                pr=prices[index];
                res=max(res,pr);
            }
            else
            {
                pr=profit(prices,0,index+1,transaction,dp)+prices[index];
            }
        }
        int npr=0;    
        npr=profit(prices,hold,index+1,transaction,dp);   
        dp[index][hold][transaction]=max(pr,npr);
    }
    return dp[index][hold][transaction];
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        res=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(4,-1)));
        return profit(prices,0,0,0,dp);
    }
};


//Method-3 : Meomization
//Putting cap while selling for more optimization


int res=0;
int profit(vector<int>&prices,int hold,int index,int transaction,vector<vector<vector<int>>>&dp)
{
    int pr=0;
    if(index==prices.size() || transaction==0)
        return 0;
    
    if(dp[index][hold][transaction]==-1)
    {
        if(hold==0)
        {
            pr=profit(prices,1,index+1,transaction,dp)-prices[index];
        }
        else if(hold==1)
        {
            
            pr=profit(prices,0,index+1,transaction-1,dp)+prices[index];
            
        }
        int npr=0;    
        npr=profit(prices,hold,index+1,transaction,dp);   
        dp[index][hold][transaction]=max(pr,npr);
    }
    return dp[index][hold][transaction];
}
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        res=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(4,-1)));
        return profit(prices,0,0,2,dp);
    }
};

//Method-4 : Tabuation

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        res=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        //Already intial element are 0 and base case output is also 0 , so we can remove it to save time , but it give us idea which loop will rum from where to where.
        //Converting 1st base case
        // for(int i=0;i<2;i++)
        // {
        //     for(int j=0;j<3;j++)
        //     {
        //         dp[n][i][j]=0;
        //     }
        // }
        
        //Converting 2nd base case
        
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<2;j++)
        //     {
        //         dp[i][j][0]=0;
        //     }
        // }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                for(int k=2;k>0;k--)
                {
                    int pr=0;
                    if(j==0)
                    {
                        pr=dp[i+1][1][k]-prices[i];
                    }
                    else if(j==1)
                    {
                        pr=dp[i+1][0][k-1]+prices[i];     
                    }
                    int npr=dp[i+1][j][k];    
                    dp[i][j][k]=max(pr,npr);
                }
            }
        }
        
        return dp[0][0][2];//Our intial call will contain the answer    
    }
};


//Method-5 : Space Optimization

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        res=0;
        int n=prices.size();     
        vector<vector<int>>dp(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                for(int k=2;k>0;k--)
                {
                    int pr=0;
                    if(j==0)
                    {
                        pr=dp[1][k]-prices[i];
                    }
                    else if(j==1)
                    {
                        pr=dp[0][k-1]+prices[i];     
                    }
                    int npr=dp[j][k];    
                    curr[j][k]=max(pr,npr);
                }
            }
            dp=curr;
        }        
        return dp[0][2];  
    }
};
