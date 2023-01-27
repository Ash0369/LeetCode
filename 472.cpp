bool dfs(int index,string curr,string &s,set<string>&st)
{
    if(index==s.size()-1)
    {
        curr.push_back(s[index]);
        if(st.find(curr)!=st.end() && (curr!=s))
        {
            return true;
        }
        return false;
        
    }
    
    curr.push_back(s[index]);
    bool a=false;
    bool b=false;
    if(st.find(curr)!=st.end())
    {
        a=dfs(index+1,"",s,st);
    }
    b=dfs(index+1,curr,s,st);
    
    return a|b;
}
class Solution 
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        set<string>st;
        for(auto x:words)
            st.insert(x);
       // cout<<st.size()<<endl;
        vector<string>ans;
        for(auto x:words)
        {
            string temp="";
            bool res=dfs(0,temp,x,st);
            if(res)
                ans.push_back(x);
        }
        return ans;
    }
};
