#define ll long long
class Solution 
{
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        ll int ans=0;
        ll int prev=0;
        int left=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                left=i+1;
                prev=0;
            }
            else
            {
                ans=ans+prev+1;
                prev=prev+1;
            }
        }
        return ans;
    }
};
