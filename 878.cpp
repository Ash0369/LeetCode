#define ll long long
class Solution 
{
public:
    int nthMagicalNumber(int n, int a, int b) 
    {
        int mod=1e9+7;
        ll int left=0;
        ll int right=1LL*n*min(a,b);
        ll int ans=right;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            ll int na=mid/a;
            ll int nb=mid/b;
            ll int nc=mid/((a*b)/(__gcd(a,b)));
            
            if((na+nb-nc)>=n)
            {
                if(mid%a==0 || mid%b==0)
                {
                    ans=mid;
                }
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans%mod;
    }
};
