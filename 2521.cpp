class Solution 
{
public:
    int distinctPrimeFactors(vector<int>& nums) 
    {
        unordered_set<int>st;
        for(auto x:nums)
        {
            int d=2;
            while(x>1 && d<=sqrt(1000))
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
            if(x!=1)
            {
                st.insert(x);
            }
        }
        return st.size();
    }
};
