#define ll long long
class Solution 
{
public:
     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) 
    {
        vector<ll int>ans;
        ll int sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<ll int>dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+nums[i];
        }
        for(auto x:queries)
        {
            int ele=x;
            auto ind=lower_bound(nums.begin(),nums.end(),ele);
            ll int sum1=0;
            ll int sum2=0;
            int i=0;
            if(ind==nums.begin())
            {
                sum1=0;
                sum2=dp[n-1];
                i=-1;
            }
            else
            {
                ind--;
                i=ind-nums.begin();
                sum1=dp[i];
                sum2=dp[n-1]-dp[i];
            }
            
            
            ll int sum_to_increase=abs(sum1-(1LL*(i+1)*ele));
            ll int sum_to_decrease=abs(sum2-(1LL*(n-i-1)*ele));
            ans.push_back(sum_to_increase+sum_to_decrease);
        }
        return ans;
    }
};
