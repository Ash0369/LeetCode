class Solution 
{
public:
    int sumOfBeauties(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int mx=0;
        for(int i=1;i<n;i++)
        {
            mx=max(mx,nums[i-1]);
            prefix[i]=mx;
        }
        int mn=INT_MAX;
        for(int i=n-2;i>=0;i--)
        {
            mn=min(mn,nums[i+1]);
            suffix[i]=mn;
        }
        int sum=0;
        
        for(int j=1;j<n-1;j++)
        {
            int val=nums[j];
            if(val>prefix[j] && val<suffix[j])
            {
                
                sum+=2;
            }
            else if(val>nums[j-1] && val<nums[j+1])
            {
                sum++;
            }
        }
        return sum;
    }
};
