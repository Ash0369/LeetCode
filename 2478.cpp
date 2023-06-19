#define ll long long
int mod=1e9+7;
bool check(char &c)
{
    if(c=='2' || c=='3' || c=='5' || c=='7')
    {
        return true;
    }
    return false;
}
ll int dfs(int index,string &s,int k,int ml,vector<vector<ll int>>&dp)
{
    if(k<0)
    {
        return 0;
    }
    if(index>=s.size())
    {
        if(index>s.size() || check(s[index-1]))
        {
            return 0;
        }
        
        return k==1;
    }
    if(dp[index][k]!=-1)
    {
        return dp[index][k];
    }
    ll int ans1=0;
    ll int ans2=0;
    if(index==0)
    {
        if(check(s[index]))
        {
            return dp[index][k]=dfs(index+ml,s,k,ml,dp);
        }
        else
        {
            return dp[index][k]=0;
        }
    }
    
    //Now len is grt or equal to ml
    //Not end
    ans1=dfs(index+1,s,k,ml,dp);
    if(check(s[index-1])==true || check(s[index])==false)
    {
        //cannot end at prime
        return dp[index][k]=ans1;
    }
    
    //End 
    ans2=dfs(index+ml,s,k-1,ml,dp);
    return dp[index][k]=(ans1+ans2)%mod;
    
}
class Solution 
{
public:
    int beautifulPartitions(string s, int k, int minLength) 
    {
        int n=s.size();
        vector<vector<ll int>>dp(n+5,vector<ll int>(k+5,-1));
        return dfs(0,s,k,minLength,dp);
    }
};
