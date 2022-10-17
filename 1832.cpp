//Method-1 : 


class Solution 
{
public:
    bool checkIfPangram(string sentence) 
    {
        set<char>st;
        for(int i=0;i<sentence.size();i++)
        {
            char c=sentence[i];
            st.insert(c);
        }
        if(st.size()==26)
            return true;
        return false;
    }
};
