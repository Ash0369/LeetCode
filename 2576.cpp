bool check(int k,vector<int>&nums)
{
    int n=nums.size();
    int matcher=k;
    for(int i=0;i<k;i++)
    {
        int val=2*nums[i];
        while(matcher<n && nums[matcher]<val)
        {
            matcher++;
        }
        if(matcher==n)
        {
            return false;
        }
        matcher++;
    }
    return true;
}
class Solution 
{
public:
    int maxNumOfMarkedIndices(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int ans=left;
        int right=(n/2)+1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(mid,nums))
            {
                ans=max(ans,mid);
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return (2*ans);
    }
};
