void dfs(string &s,string &start ,vector<string>&curr,vector<vector<string>>&ans,map<string,int>&mp)
{
    if(s==start)
    {
        reverse(curr.begin(),curr.end());
        ans.push_back(curr);
        reverse(curr.begin(),curr.end());
        return;
    }
    int no=mp[s];
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        for(int j=97;j<=122;j++)
        {
            s[i]=char(j);
            if(s[i]==c)
                continue;
            if(mp.find(s)!=mp.end() && mp[s]<no)
            {
                curr.push_back(s);
                dfs(s,start,curr,ans,mp);
                curr.pop_back();
            }
        }
        s[i]=c;
    }
}
class Solution 
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string>q;
        map<string,int>mp;
        mp[beginWord]=0;
        q.push(beginWord);
        set<string>st;
        for(auto x:wordList)
            st.insert(x);
        st.erase(beginWord);
        int pos=1;
        while(!q.empty())
        {
            int n=q.size();
            for(int iter=0;iter<n;iter++)
            {
                auto node=q.front();
                q.pop();
                string s=node;
                
                for(int j=0;j<s.length();j++)
                {
                    for(int i=97;i<=122;i++)
                    {
                        char c=char(i);
                        string temp=s;
                        temp[j]=c;
                        if(st.find(temp)!=st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                            mp[temp]=pos;
                        }
                    }
                }
            }
            pos++;
        }
        vector<string>curr;
        curr.push_back(endWord);
        vector<vector<string>>ans;
        dfs(endWord,beginWord,curr,ans,mp);
        return ans;
        
    }
};
