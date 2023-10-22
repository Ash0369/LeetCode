class Solution 
{
public:
    int minimumSum(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=1e9;
        vector<int>smallest(n+1,1e9);
        smallest[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            smallest[i]=min(smallest[i+1],nums[i]);
        }
        int g=nums[0];
        for(int i=1;i<n-1;i++)
        {
            if(g<nums[i] && smallest[i+1]<nums[i])
            ans=min(ans,g+smallest[i+1]+nums[i]);
          
            g=min(g,nums[i]);
        }
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
};
