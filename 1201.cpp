#define ll long long
ll int lcm(int a,int b)
{
    return ((1LL*a)*b)/(__gcd(a,b));
}
class Solution 
{
public:
   
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        ll int low=min(a,min(b,c));
        ll int up=n*low;
        ll int ans;
        while(low<=up)
        {
            ll int mid=(low+up)/2;
            int cnt=0;
            cnt+=mid/a;
            cnt+=mid/b;
            cnt+=mid/c;
            
            cnt-=mid/(lcm(a,b));
            cnt-=mid/(lcm(b,c));
            cnt-=mid/(lcm(a,c));
            
            cnt+=mid/(lcm(a,lcm(b,c)));
            
            if(cnt>=n)
            {
                ans=mid;
                up=mid-1;
            }
            else
                low=mid+1;
            
        }
        return ans;
    }
};
