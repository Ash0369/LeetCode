//Method-1 : 

class Solution 
{
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.size();
        int last_z=-1;
        vector<int>one(n+1,0);
        vector<int>zero(n+1,0);
        for(int i=n;i>=0;i--)
        {
            if(i==n)
            {
                one[i]=0;
                zero[i]=0;
            }
            else if(s[i]=='1')
            {
                one[i]=one[i+1]+1;
                zero[i]=zero[i+1];
            }
            else
            {
                one[i]=one[i+1];
                zero[i]=zero[i+1]+1;
            }
        }
        int to=one[0];
        int ans=n;
        for(int i=0;i<=n;i++)
        {
            int op=to-one[i]+zero[i];
            ans=min(ans,op);
        }
        return ans;
    }
};


//Method-2 : 

class Solution 
{
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=1;j++)
            {
                if(j==0)
                {
                    //Not fliped
                    if(s[i]=='0' && s[i-1]=='1')
                    {
                        dp[i][j]=dp[i-1][1];
                    }
                    else if(s[i]=='0' && s[i-1]=='0')
                    {
                        dp[i][j]=dp[i-1][0];
                    }
                    else
                    {
                        dp[i][j]=min(dp[i-1][0],dp[i-1][1]);
                    }
                }
                else
                {
                    //Flipped
                    if(s[i]=='1' && s[i-1]=='1')
                    {
                        dp[i][j]=1+dp[i-1][1];
                    }
                    else if(s[i]=='1' && s[i-1]=='0')
                    {
                        dp[i][j]=1+dp[i-1][0];
                    }
                    else
                    {
                        dp[i][j]=1+min(dp[i-1][0],dp[i-1][1]);
                    }
                }
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};
