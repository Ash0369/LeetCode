#define ll long long
class Solution 
{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            int index1=lower_bound(nums.begin(),nums.end(),lower-nums[i])-nums.begin();
            int index2=upper_bound(nums.begin(),nums.end(),upper-nums[i])-nums.begin();
            index2--;
            index1=max(i+1,index1);
            index2=max(i+1,index2);
            if(index1==n)
            {
                continue;
            }
            if(nums[i]+nums[index1]<lower || nums[i]+nums[index2]>upper)
            {
                continue;
            }
            ans+=index2-index1+1; 
        }
        return ans;
    }
};
