int search(vector<int>&nums,int l,int r,int k,vector<int>&res)
{
    if(r<l)
    {
        return -1;
    }
    int index=(l+r)/2;
    int ele=nums[index];
    if(ele==k)
    {
        int left=INT_MIN;
        int right;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]==k && left==INT_MIN)
            {
                left=i;
            }
            if(nums[i]==k)
            {
                right=i;
            }
        }
        res.push_back(left);
        res.push_back(right);
        return index;
    }
    if(ele>k)
    {
        return  search(nums,l,index-1,k,res);
    }
    
    return search(nums,index+1,r,k,res);
    
}
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>res;
        search(nums,0,nums.size()-1,target,res);
        if(res.empty())
        {
            res={-1,-1};
        }
        return res;
    }
};
