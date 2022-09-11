int search_min_index(vector<int>& nums,int l,int r)
{
    if(l>r)
    {
        return -1;
    }
    int n=nums.size();
    int index=(l+r)/2;
    int next=(index+1)%n;
    int prev=(index+n-1)%n;
    
    if(nums[index]<nums[prev] && nums[index]<nums[next])
        return index;
    else if(nums[index]>=nums[0])
        return search_min_index(nums,index+1,r);
    else if(nums[index]<=nums[n-1])
        return search_min_index(nums,l,index-1);
    return -1;
}
int binary_search(vector<int>& nums, int target,int l,int r )
{
    if(l>r)
    {
        return -1;
    }
    int index=(l+r)/2;
    if(nums[index]==target)
    {
        return index;
    }
    if(nums[index]>target)
    {
        return binary_search(nums,target,l,index-1);
    }
    return binary_search(nums,target,index+1,r);
}
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int min_index=search_min_index(nums,0,nums.size()-1);
        if(min_index==-1)
            min_index=1;
        int a=binary_search(nums,target,0,min_index-1);
        if(a!=-1)
            return a;        
        return binary_search(nums,target,min_index,nums.size()-1);
    }
};
