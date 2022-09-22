bool check(vector<int>&nums,int m,int &mid)
{
    int sum=0;
    for(auto x:nums)
    {
        if(sum+x>mid)
        {
            m--;
            sum=0;
        }
        
        sum=sum+x;
        if(m==0)
            return false;
    }
    return true;
}

class Solution 
{
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int low=INT_MIN;
        int high=0;
        for(auto x:nums)
        {
            high=high+x;
            low=max(low,x);
        }
        int ans=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(nums,m,mid))
            {
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
