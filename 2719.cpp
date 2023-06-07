int mx=0;
int mn=0;
int mod=1e9+7;
#define ll long long

ll int dp[30][500][2];
int fxn(string &num,int n,int x,bool tight)
{
    if(n==0)
    {
        if(x>=mn && x<=mx)
        {
            return 1;
        }
        return 0;
    }
    if(dp[n][x][tight]!=-1)
    {
        return dp[n][x][tight];
    }
    int ub=9;
    if(tight==1)
    {
        ub=num[num.size()-n]-'0';
    }
    int ans=0;
    for(int dig=0;dig<=ub;dig++)
    {
        ans=(ans+fxn(num,n-1,x+dig,tight&(dig==ub)))%mod;
    }
    return dp[n][x][tight]=ans;
}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
class Solution 
{
public:
    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        mx=max_sum;
        mn=min_sum;
        memset(dp,-1,sizeof(dp));
        int ans1=fxn(num2,num2.size(),0,true);
         memset(dp,-1,sizeof(dp));
        int ans2=fxn(num1,num1.size(),0,true);
        
        int sum=0;
        
        for(auto x:num1)
        {
            sum+=(x-'0');
        }
        if(sum>=min_sum && sum<=max_sum)
        {
            ans2--;
        }
        return mod_sub(ans1,ans2);
    }
};
