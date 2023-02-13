class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int d=nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++)
            {
                if((nums[j]-nums[j-1])==d)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};
