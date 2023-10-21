class Solution 
{
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>dp(n+10,0);
        multiset<int>st;
        int ans=-1e9;
        int ptr=0;
        for(int i=0;i<n;i++)
        {
            if(st.size()>0)
            {
                int prev=*st.rbegin();
                //Either inculde it or not inculde it
                dp[i]=max(nums[i],nums[i]+prev);
                if(i-ptr>=k)
                {
                    st.erase(st.find(dp[ptr]));
                    ptr++;
                }
                st.insert(dp[i]);
            }
            else
            {
                dp[i]=nums[i];
                st.insert(dp[i]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
