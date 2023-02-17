#define ll long long
bool check(int mid,vector<int>&nums)
{
    ll int available=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid)
        {
            if(available>=(nums[i]-mid))
            {
                available-=(nums[i]-mid);
            }
            else
            {
                return false;
            }
        }
        else
        {
            available+=(mid-nums[i]);
        }
    }
    return true;
}
class Solution 
{
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        int right=0;
        for(auto x:nums)
        {
            right=max(right,x);
        }
        int left=0;
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(mid,nums))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
