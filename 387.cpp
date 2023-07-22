class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        vector<int>dp(26,0);
        for(auto x:s)
        {
            dp[x-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(dp[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};
