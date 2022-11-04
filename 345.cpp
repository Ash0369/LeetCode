class Solution 
{
public:
    string reverseVowels(string s) 
    {
        set<char>st;
        st.insert('a');
        st.insert('A');
        st.insert('e');
        st.insert('E');
        st.insert('i');
        st.insert('I');
        st.insert('o');
        st.insert('O');
        st.insert('u');
        st.insert('U');
        int start=0;
        int end=s.length();
        while(start<=end)
        {
            if(st.find(s[start])!=st.end())
            {
                while(st.find(s[end])==st.end())
                    end--;
                swap(s[start],s[end]);
                end--;
            }
            start++;
        }
        return s;
    }
};
