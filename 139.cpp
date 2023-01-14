int n;
bool play(string s,int index,string last,set<string>&st,map<pair<int,string>,bool>&mp)
{
    if(index>n)
        return false;
    if(index==n)
    {
        if(st.find(last)!=st.end())
            return true;
        return false;
    }
    if(mp.find({index,last})!=mp.end())
        return mp[{index,last}];
    
    bool res1=false;
    if(st.find(last)!=st.end())
    {
        string a;
        a.push_back(s[index]);
        res1=play(s,index+1,a,st,mp);
    }
    last.push_back(s[index]);
    bool res2=play(s,index+1,last,st,mp);   
    return mp[{index,last}]=res1|res2;
}
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        n=s.size();
        set<string>st(wordDict.begin(),wordDict.end());
        map<pair<int,string>,bool>mp;
        return play(s,0,"",st,mp);
    }
};
