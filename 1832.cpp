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


//Method-2 : 


class Solution 
{
public:
    bool checkIfPangram(string sentence) 
    {
        vector<int>vec(26,0);
        for(int i=0;i<sentence.size();i++)
        {
            char c=sentence[i];
            vec[c-'a']=1;
        }
        for(auto x:vec)
        {
            if(x==0)
                return false;
        }
        return true;
    }
};
