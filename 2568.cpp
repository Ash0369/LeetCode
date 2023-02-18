class Solution 
{
public:
    int minImpossibleOR(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_set<int>st;
        for(auto x:nums)
        {
            st.insert(x);
        }
        int ele=1;
        while(true)
        {
            if(st.find(ele)==st.end())
            {
                return ele;
            }
            ele=ele*2;
        }
        return -1;
        
    }
};
