class Solution 
{
public:
    string smallestSubsequence(string s) 
    {
        int n=s.size();
        stack<int>st;
        vector<vector<int>>dp(n+1,vector<int>(26,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
            {
                dp[i][j]=dp[i+1][j];
            }
            dp[i][s[i]-'a']++;
        }
        vector<int>dp1(26,0);
        for(int i=0;i<n;i++)
        {
            if(dp1[s[i]-'a']==1)
            {
                continue;
            }
            while(!st.empty() && dp[i+1][st.top()]>0 && ((s[i]-'a')<st.top()))
            {
                dp1[st.top()]=0;
                st.pop();
            }
            dp1[s[i]-'a']=1;
            st.push(s[i]-'a');
        }
        string ans="";
        while(!st.empty())
        {
            ans.push_back(st.top()+'a');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
