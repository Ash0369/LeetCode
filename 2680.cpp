#define ll long long
class Solution 
{
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>pre(n+2,0);
        vector<int>suf(n+2,0);
        
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]|nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]|nums[i+1];
        }
        
        ll int ans=0;
        ll int mul=pow(2,k);
        for(int i=0;i<n;i++)
        {
            ll int temp=(mul*nums[i])|(pre[i]|suf[i]);
            ans=max(ans,temp);
        }
        return ans;
    }
};
