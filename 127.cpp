//Method-1 : DFS --> It will give TLE after test case 25


int op(string &start,string &dest,int cnt,set<string>&st,map<string,int>&visited)
{
    if(start==dest && cnt!=0)
        return cnt;
    int ans=INT_MAX;
    visited[start]=cnt;
    for(int i=0;i<start.size();i++)
    {
        for(int j=97;j<=122;j++)
        {
            if(start[i]!=char(j))
            {
                string temp=start;
                temp[i]=char(j);
                if(st.find(temp)!=st.end() && (visited.find(temp)==visited.end() || visited[temp]>cnt))
                {
                    int a=op(temp,dest,cnt+1,st,visited);
                    ans=min(ans,a);
                }
            }
        }
    }
    return ans;
}
class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>&wordList) 
    {
        set<string>st;
        map<string,int>visited;
        for(auto x:wordList)
        {
            st.insert(x);
        }
        if(st.find(endWord)==st.end())
            return 0;
        int ans=op(beginWord,endWord,0,st,visited);
        if(ans==INT_MAX)
            return 0;
        return ans+1;
    }
};


//Method-2 -->BFS It will give TLE after 34 Test case but will pass in GFG

class Solution 
{
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st;
        for(auto x:wordList)
            st.insert(x);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            string s=node.first;
            int pos=node.second;
            if(s==endWord)
                return pos;
            st.erase(s);
            
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
                    }
                }
            }
        }
        return 0;
    }
};


//Method-3 : Passed

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
