//Memoization

const int mod=1e9+7;
int dfs(string &s,int k,int index,vector<int>&dp)
{
    int n=s.size();
    if(index==n)
    {
        return 1;
    }
    string temp="";
    int ans=0;
    if(s[index]=='0')
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    for(int i=0;i<=10;i++)
    {
        if(index+i>=n)
        {
            break;
        }
        temp.push_back(s[index+i]);
        long long int num=stoll(temp);
        if(num>k)
        {
            break;
        }
        ans=(1LL*ans+dfs(s,k,index+i+1,dp))%mod;
    }
    return dp[index]=ans;
}
class Solution 
{
public:
    int numberOfArrays(string s, int k) 
    {
        vector<int>dp(s.size()+2,-1);
        return dfs(s,k,0,dp);
    }
};


//Recursive

const int mod=1e9+7;
class Solution 
{
public:
    int numberOfArrays(string s, int k) 
    {
        int n=s.size();
        vector<int>dp(n+2,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            string temp="";
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            for(int j=0;j<=10;j++)
            {
                if(i+j>=n)
                {
                    break;
                }
                temp.push_back(s[i+j]);
                long long int num=stoll(temp);
                if(num>k)
                {
                    break;
                }
                dp[i]=(dp[i]+dp[i+j+1])%mod;
            }
        }
        return dp[0];
    }
};
