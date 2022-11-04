class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int ans=INT_MIN;
        int curr=0;
        for(auto x:nums)
        {
            curr+=x;
            if(curr>ans)
                ans=curr;
            if(curr<0)
                curr=0;
        }
        return ans;
    }
};
