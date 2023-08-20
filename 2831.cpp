class Solution 
{
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        map<int,int>mp;
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++)
        {
            
            mp[nums[right]]++;
            int diff=right-left+1-(mp[nums[left]]);
            if(diff>k)
            {
                mp[nums[left]]--;
                left++;
            }
            diff=right-left+1-(mp[nums[left]]);
            
            if(diff<=k)
            ans=max(ans,mp[nums[left]]);
            
        }
        while(left<n)
        {
            int diff=(n-left)-(mp[nums[left]]);
            if(diff<=k)
            ans=max(ans,mp[nums[left]]);
            
            left++;
        }
        return ans;
    }
};
