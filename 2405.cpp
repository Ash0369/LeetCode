class Solution 
{
public:
    int partitionString(string s) 
    {
        int count=0;
        set<char>st;
        for(auto x:s)
        {
            if(st.find(x)!=st.end())
            {
                count++;
                st.clear();
            }
            st.insert(x);
        }
        return count+1;
    }
};
