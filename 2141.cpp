#define ll long long
class Solution 
{
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        int m=batteries.size();
        ll int ans=0;
        ll int left=0;
        ll int right=1e14;
        
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            ll int supply=0;
            for(auto x:batteries)
            {
                supply+=min(mid,1LL*x);
            }
            if(supply>=(n*mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
    
};
