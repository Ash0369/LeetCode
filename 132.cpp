//Method-1 :

bool palindrome(int start,int end,string &s)
{
    while(start<end)
    {
        if(s[start]!=s[end])
            return false;
        
        start++;
        end--;
    }
    return true;
}
int cut(string &s,int index,vector<int>&dp)
{
    if(index>=s.length())
    {
        return 0;
    }
    int ans=INT_MAX;
    int count=0;
    if(dp[index]==-1)
    {
        for(int i=index;i<s.length();i++)
        {
            if(palindrome(index,i,s))
            {
                count=1+cut(s,i+1,dp);
                ans=min(count,ans);
            }
        }
        dp[index]=ans;
    }
    return dp[index];
}
class Solution 
{
public:
    int minCut(string s) 
    {
        vector<int>dp(s.length()+1,-1);
        return cut(s,0,dp)-1; //As we done a partion at end also
    }
};
