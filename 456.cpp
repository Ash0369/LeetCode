class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n=nums.size();
        multiset<int>st;
        for(int i=1;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int mn=nums[0];
        for(int j=1;j<n;j++)
        {
            st.erase(st.find(nums[j]));
            
            //(j) is centre point
            
            if(mn<nums[j])
            {
                auto lb=st.upper_bound(mn);
                if(lb!=st.end() && (*lb)<nums[j])
                {
                    return true;
                }
            }
            mn=min(mn,nums[j]);
            
        }
        return false;
    }
};
