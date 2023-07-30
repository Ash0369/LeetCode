int mod=1e9+7;

#define ll long long
ll int dp[105][11][2][2];
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
ll int dfs(string &s,int n,int prev,bool tight,bool change)
{
    if(n==0)
    {
        return 1;
    }
    int ub=9;
    if(tight==true)
    {
        ub=s[s.size()-n]-'0';
    }
    if(dp[n][prev][tight][change]!=-1)
    {
        return dp[n][prev][tight][change];
    }
    ll int ans=0;
    if(prev==10 ||(prev==0 && change==false))
    {
        for(int dig=0;dig<=ub;dig++)
        {
            ans=(ans+dfs(s,n-1,dig,tight&(dig==ub),(dig!=0)))%mod;
        }
    }
    else
    {
        //2 option 1 more or 1 less
        
        if(prev-1>=0 && prev-1<=ub)
        {
            ans=(ans+dfs(s,n-1,prev-1,tight&((prev-1)==ub),change))%mod;
        }
         if(prev+1<=ub)
        {
            ans=(ans+dfs(s,n-1,prev+1,tight&((prev+1)==ub),change))%mod;
        }
    }
    return dp[n][prev][tight][change]=ans;
    
}
class Solution 
{
public:
    int countSteppingNumbers(string low, string high) 
    {
        memset(dp,-1,sizeof(dp));
        ll int cnt1=dfs(high,high.size(),10,true,false);
        memset(dp,-1,sizeof(dp));
        ll int cnt2=dfs(low,low.size(),10,true,false);
        bool check=true;
        for(int i=1;i<low.size();i++)
        {
            int dig=low[i-1]-'0';
            int curr=low[i]-'0';
            
            if(abs(dig-curr)==1)
            {
                
            }
            else
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            cnt2=mod_sub(cnt2,1);
        }
        
        return mod_sub(cnt1,cnt2);
    }
};
