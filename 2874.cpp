#define ll long long
class Solution 
{
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n=nums.size();
        ll int ans=0;
        vector<int>suff(n+1,0);
        suff[n-1]=nums[n-1];
        int till=nums[0];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=max(nums[i],suff[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,1LL*(till-nums[i])*suff[i+1]);
            till=max(till,nums[i]);
        }
        return ans;
    }
};
