class Solution 
{
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int n=words.size();
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        vector<int>prefix(n+1,0);
        for(int i=0;i<words.size();i++)
        {
            char start=words[i][0];
            char end=words[i][words[i].size()-1];
            if(st.find(start)!=st.end() && st.find(end)!=st.end())
            {
                prefix[i+1]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            prefix[i]=prefix[i]+prefix[i-1];
        }
        
        vector<int>ans;
        
        for(auto x:queries)
        {
            int a=x[0];
            int b=x[1];
            a++;
            b++;
            ans.emplace_back(prefix[b]-prefix[a-1]);
            
        }
        return ans;
        
    }
};
