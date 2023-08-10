int bs(int left,int right,vector<int>&nums,int target)
{
    while(left<=right){
    int mid=(left+right)/2;
    if(nums[mid]==target)
        return true;
    
    if(nums[mid]==nums[left] && nums[mid]==nums[right])
    {
        left++;
        right--;
    }
    else if(nums[mid]>=nums[left])
    {
        if(target>=nums[left] && target<nums[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    else
    {
        if(target<=nums[right] && target>nums[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    }
    return false;
}
class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        if(n==1 || n==2)
        {
            if(n==1) return nums[0]==target;
            else return nums[0]==target || nums[1]==target;
        }
        return bs(0,n-1,nums,target);
    }
};
