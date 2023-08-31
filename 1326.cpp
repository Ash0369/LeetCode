//Method-1 : 

class Solution 
{
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int>dp(n+2,1e9);
        for(int i=0;i<=n;i++)
        {
            for(int j=-1;j<i;j++)
            {
                if(j==-1)
                {
                    if(ranges[i]>=i)
                    {
                        dp[i]=1;
                    }
                    else
                    {
                        dp[i]=n+10;
                    }
                }
                else
                {
                    if(j+ranges[j]>=i-ranges[i] && dp[j]!=-1)
                    {
                        dp[i]=min(dp[i],1+dp[j]);
                    }
                    else
                    {
                        dp[i]=min(dp[i],n+10);
                    }
                    if(i==n && j+ranges[j]>=n)
                    {
                        dp[i]=min(dp[i],dp[j]);
                    }
                }
            }
        }
        if(dp[n]>n)
        {
            return -1;
        }
        return dp[n];
    }
};

//Method-2 : 

class Solution 
{
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int>dp(n+2,n+10);
        dp[0]=0;
        for(int i=0;i<=n;i++)
        {
           for(int j=max(0,i-ranges[i]);j<=min(n,i+ranges[i]);j++)
           {
               dp[j]=min(dp[j],1+dp[max(0,i-ranges[i])]);
           }
        }
        if(dp[n]>n)
        {
            return -1;
        }
        return dp[n];
    }
};
