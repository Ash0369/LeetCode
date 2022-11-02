//Method-1

class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st;
        for(auto x:wordList)
            st.insert(x);
        st.erase(beginWord);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            string s=node.first;
            int pos=node.second;
            if(s==endWord)
                return pos;
            
            
            for(int j=0;j<s.length();j++)
            {
                for(int i=97;i<=126;i++)
                {
                    char c=char(i);
                    string temp=s;
                    temp[j]=c;
                    if(st.find(temp)!=st.end())
                    {
                        q.push({temp,pos+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};


//Method-2:

class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string>q;
        map<string,int>mp;
        mp[beginWord]=1;
        q.push(beginWord);
        set<string>st;
        for(auto x:wordList)
            st.insert(x);
        st.erase(beginWord);
        int pos=2;
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
                    for(int i=97;i<=126;i++)
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
        return mp[endWord];
    }
};
