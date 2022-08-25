class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char,int>mp1;
        map<char,int>mp2;
        
        for(auto c:ransomNote)
        {
            mp1[c]++;
        }
        for(auto c:magazine)
        {
            mp2[c]++;
        }

        for(auto x:mp1)
        {
            if(mp2.find(x.first)!=mp2.end())
            {
                if(mp2[x.first]<x.second)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
