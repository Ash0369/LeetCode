#define ll long long
#define mod 1000000007

ll int power(ll int n,int k)
{
    if(n==0)
        return 1;
    ll int ans=power(n/2,k);
    ans=(ans*ans)%mod;
    if(n%2==0)
        return ans;
    return (ans*k)%mod;
}
class Solution
{
public:
    int countGoodNumbers(long long n) 
    {
        if(n%2==0)
        {
            ll int five=power(n/2,5);
            ll int four=power(n/2,4);
            
            return (five*four)%mod;
        }
        else
        {
            ll int five=power((n/2)+1,5);
            ll int four=power(n/2,4);
            
            return (five*four)%mod;
        }
    }
};
