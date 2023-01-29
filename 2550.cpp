#define ll long long
class Solution 
{
public:
    int mod=2*(1e9+7);
    int md=1e9+7;
    ll int bpow(int n)
    {
        if(n==0)
            return 1;
        
        ll int a=bpow(n/2);
        if(n%2==0)
        {
            ll int b=(1LL*a*a)%mod;
            return b;
        }
        else
        {
            ll int b=(1LL*a*a)%mod;
            return (1LL*b*2)%mod;
        }
    }
    int monkeyMove(int n) 
    {
        return (bpow(n)-2)%md;
    }
};
