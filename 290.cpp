class Solution 
{
public:
    bool wordPattern(string pattern, string s) 
    {
        map<char,string>mp;
        map<string,char>dmp;
        
        stringstream ss(s);
        string word;
        int cnt=0;
        while(ss>>word)
        {
            if(cnt==pattern.size())
                return false;
            char x=pattern[cnt];
            if(mp.find(x)==mp.end())
            {
                if(dmp.find(word)!=dmp.end())
                    return false;
                mp[x]=word;
                dmp[word]=x;
            }
            else
            {
                if(mp[x]!=word)
                {
                    return false;
                }
            }
            cnt++;
        }
        if(cnt!=pattern.size())
            return false;
        return true;
    }
};
