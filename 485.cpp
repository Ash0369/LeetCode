class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                int ans=1;
                i++;
                while(i<n && nums[i]==1)
                {
                    ans++;
                    i++;
                }
                mx=max(mx,ans);
            }
        }
        return mx;
    }
};
