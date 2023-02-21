class Solution 
{
public:
    int distinctPrimeFactors(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<int>st;
        for(auto x:nums)
        {
            int d=2;
            while(x>1)
            {
                if(x%d==0)
                {
                    st.insert(d);
                    x=x/d;
                }
                else
                {
                    d++;
                }
            }
        }
        return st.size();
    }
};
