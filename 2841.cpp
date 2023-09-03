#define ll long long
class Solution 
{
public:
    long long maxSum(vector<int>& nums, int m, int k) 
    {
        map<int,int>mp;
        int left=0;
        int n=nums.size();
        ll int ans=0;
        ll int tot=0;
        int d=0;
        for(int i=0;i<n;i++)
        {
            tot+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1)
            {
                d++;
            }
            if((i-left+1)<k)
            {
                continue;
            }
            if(d>=m)
            {
                ans=max(ans,tot);
            }
            mp[nums[left]]--;
            if(mp[nums[left]]==0)
            {
                d--;
            }
            tot=tot-nums[left];
            left++;
        }
        return ans;
        
    }
};
