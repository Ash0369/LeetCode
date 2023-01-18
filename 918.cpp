class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int total=0;
        int n=nums.size();
        int minsum=INT_MAX;
        int maxsum=nums[0];
        int currmin=INT_MAX;
        int currmax=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
            
            currmax=max(currmax,0)+nums[i];
            currmin=min(currmin,0)+nums[i];
            minsum=min(minsum,currmin);
            maxsum=max(maxsum,currmax);
        }
        if(total==minsum)
        {
            return maxsum;
        }
        return max(maxsum,total-minsum);
    }
};
