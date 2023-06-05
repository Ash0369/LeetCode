class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int ans=1e9;
        int d=1e9;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int k=n-1;
            int j=i+1;
            while(j<k)
            {
                if(d>(abs(nums[i]+nums[j]+nums[k]-target)))
                {
                    d=abs(nums[i]+nums[j]+nums[k]-target);
                    ans=nums[i]+nums[j]+nums[k];
                }
                if((nums[i]+nums[j]+nums[k])>=target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};
