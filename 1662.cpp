class Solution 
{
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string st1="";
        string st2="";
        for(auto x:word1)
            st1+=x;
        for(auto x:word2)
            st2+=x;
        
        if(st1==st2)
            return true;
        return false;
    }
};
