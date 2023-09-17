class Solution 
{
public:
    int countWays(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int tot=0;
        int n=nums.size();
        if(nums[0]>0)
        {
            ans++;
        }
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            i++;
            while(i<n && nums[i]==curr)
            {
                i++;
            }
            i--;
            int tot=i+1;
            if(i==n-1 || (nums[i+1]>tot && nums[i]<tot))
            {
                ans++;
            }
        }
        return ans;
    }
};
