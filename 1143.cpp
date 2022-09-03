int longest(string &text1,string &text2,int x1,int x2,vector<vector<int>>&dp)
{
    if(x1<0 || x2<0)
    {
        return 0;
    }
    if(text1[x1]==text2[x2])
    {
       return 1+ longest(text1,text2,x1-1,x2-1,dp);
    }
    else
    {
        if(dp[x1][x2]==-1)
        {
            int a=longest(text1,text2,x1-1,x2,dp);
            int b=longest(text1,text2,x1,x2-1,dp);
            dp[x1][x2]=max(a,b);
        }
        return dp[x1][x2];
    }
}
class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return longest(text1,text2,n1-1,n2-1,dp);
    }
};
