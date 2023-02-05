int ans=INT_MAX;
bool chor(int mid,vector<int>&nums,int k)
{
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<=mid)
        {
            cnt++;
            i++;
        }
    }
    
    return cnt>=k;
}
class Solution 
{
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int n=nums.size();
        
        int mx=0;
        for(auto x:nums)
        {
            mx=max(x,mx);
        }
        int left=0;
        int right=mx;
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            
            if(chor(mid,nums,k))
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
