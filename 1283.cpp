//Method-1 :

bool smallest(vector<int>&nums,int &mid,int &threshold)
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%mid==0)
            sum=sum+(nums[i]/mid);
        else
            sum=sum+(nums[i]/mid)+1;
        
        if(sum>threshold)
            return false;
    }
    return true;
}
class Solution 
{
public:
    int smallestDivisor(vector<int>&nums, int threshold) 
    {
        int max_num=INT_MIN;
        for(auto x:nums)
        {
            max_num=max(max_num,x);
        }
        
        int low=1;
        int high=max_num;
        int res=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(smallest(nums,mid,threshold))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};
