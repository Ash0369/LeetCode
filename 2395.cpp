class Solution 
{
public:
    bool findSubarrays(vector<int>& nums) 
    {
        set<int>st;
        for(int i=0;i<nums.size()-1;i++)
        {
            int sum=nums[i]+nums[i+1];
            if(st.find(sum)!=st.end())
            {
                return true;
            }
            st.insert(sum);
        }
        return false;
    }
};
