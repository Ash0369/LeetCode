int binary_search(vector<int>&nums,int n,int l,int r)
{
    if(l>r)
    {
        return -1;
    }
    int mid=(l+r)/2;
    if( (mid-1<0 ||(nums[mid]>nums[mid-1]))  && (mid+1>=n || nums[mid]>nums[mid+1]))
    {
        return mid;
    }
    
    int a=binary_search(nums,n,mid+1,r);
    if(a!=-1)
        return a;
    return binary_search(nums,n,l,mid-1);
    
}
class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        return binary_search(nums,nums.size(),0,nums.size()-1);
    }
};
