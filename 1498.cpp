const int mod=1e9+7;
#define ll long long
ll int pwr(ll int a,ll int b)
{
    if(b==0)
        return 1;
    if(b%2==0){ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;return ans2;}
    ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
class Solution 
{
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        ll int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int val=nums[i];
            int req=target-val;
            if(req<0)
            {
                continue;
            }
            int index=upper_bound(nums.begin(),nums.end(),req)-nums.begin();
            index--;
            if(index<i)
            {
                continue;
            }
            int r=index-i;
            ans=(ans+pwr(2,r))%mod;
        }
        return ans;
    }
};
