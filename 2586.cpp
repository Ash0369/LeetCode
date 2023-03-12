class Solution 
{
public:
    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int cnt=0;
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for(int i=left;i<=right;i++)
        {
            int n=words[i].size();
            char c=words[i][0];
            char x=words[i][n-1];
            if(st.find(c)!=st.end() && st.find(x)!=st.end())
            {
                cnt++;
            }
        }
        return cnt;
    }
};
