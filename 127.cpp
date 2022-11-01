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
