class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)>>1;
            int val=nums[mid];
            if(val==target)
                return mid;
            else if(val>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return -1;
    }
};
