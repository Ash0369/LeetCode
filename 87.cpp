class Solution 
{
public:
    unordered_map<string,bool>mp;
    bool scramble(string s1,string s2)
    {
        int len=s1.size();
        if(len==1)
        {
            return s1==s2;
        }
        string ans=s1+s2;
        if(mp.find(ans)!=mp.end())
        {
            return mp[ans];
        }
        if(s1==s2)
        {
            return mp[ans]=true;
        }
        for(int i=1;i<len;i++)
        {
            if(scramble(s1.substr(0,i),s2.substr(0,i)) && scramble(s1.substr(i),s2.substr(i)))
            {
                return mp[ans]=true;
            }
            if(scramble(s1.substr(0,i),s2.substr(len-i)) && scramble(s1.substr(i),s2.substr(0,len-i)))
            {
                return mp[ans]=true;
            }
        }
        return mp[ans]=false;
    }
    bool isScramble(string s1, string s2) 
    {
        return scramble(s1,s2);
    }
};
