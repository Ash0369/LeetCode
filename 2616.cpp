bool check(int mid,vector<int>&nums,int p)
{
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i+1]-nums[i]<=mid)
        {
            cnt++;
            i++;
        }
    }
    return cnt>=p;
}
class Solution 
{
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        if(p==0)
        {
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int ans=right;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(mid,nums,p))
            {
                right=mid-1;
                ans=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
