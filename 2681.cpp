int mod=1e9+7;
#define ll long long
class Solution 
{
public:
    int sumOfPower(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        ll int ans=0;
        ll int prev=0;
        for(int i=0;i<n;i++)
        {
            ll int temp=0;
            prev=(2LL*prev)%mod;
            if(prev>0)
            {
                temp=(temp+prev)%mod;
            }
            temp=(temp+nums[i])%mod;
            if(i-1>=0)
            {
                temp=(temp+nums[i-1])%mod;
            }
            ans=(ans+((1LL*nums[i]*nums[i])%mod*temp)%mod)%mod;
            if(i-1>=0)
            {
                prev=prev+nums[i-1];
            }
        }
        return ans;
    }
};
