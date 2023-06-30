#define ll long long
int mod=1e9+7;
class Solution 
{
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        int index=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            return 0;
        }
        int prev=index;
        ll int ans=1;
        for(int j=index+1;j<n;j++)
        {
            if(nums[j]==1)
            {
                //can break in any from prev .. j-1
                ans=(ans*(j-1-prev+1))%mod;
                prev=j;
            }
        }
        return ans;
    }
};
