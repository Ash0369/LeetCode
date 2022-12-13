class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
            return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                curr=1;
                continue;
            }
            if(nums[i]==nums[i-1])
                continue;
            
            else if(nums[i]==nums[i-1]+1)
            {
                curr++;
                ans=max(ans,curr);
            }
            else
            {
                curr=1;
            }
        }
        return ans;
    }
};
