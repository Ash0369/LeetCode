#define ll long long
class Solution 
{
public:
    long long minimumPossibleSum(int n, int target) 
    {
        
        ll int curr=1;
        ll int ans=0;
        int av=target/2;
        av=min(n,av);
        ans=1LL*av*(av+1)/2;
        int rem=n-av;
        curr=target;
        while(rem>0)
        {
            ans+=curr;
            curr++;
            rem--;
        }
        return ans;
    }
};
