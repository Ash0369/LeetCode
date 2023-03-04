#define ll long long
class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        int left=0;
        int n=nums.size();
        int chota=-1;
        int bada=-1;
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==minK)
            {
                chota=i;
            }
            if(nums[i]==maxK)
            {
                bada=i;
            }
            else if(nums[i]<minK || nums[i]>maxK)
            {
                left=i+1;
                chota=-1;
                bada=-1;
            }
            if(chota!=-1 && bada!=-1)
            {
                ans=ans+(1LL*min(chota,bada)-left+1);
            }
        }
        return ans;
    }
};
