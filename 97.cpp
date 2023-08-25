int dp[101][101];
bool dfs(string &s1,string &s2,string &s3,int index1,int index2,int till)
{
    if(till==s3.size())
    {
        return true;
    }
    if(dp[index1][index2]!=-1)
    {
        return dp[index1][index2];
    }
    bool res=false;
    if(index1<s1.size() && s1[index1]==s3[till])
    {
        res=res|dfs(s1,s2,s3,index1+1,index2,till+1);
    }
    if(index2<s2.size() && s2[index2]==s3[till])
    {
        res=res|dfs(s1,s2,s3,index1,index2+1,till+1);
    }
    return dp[index1][index2]=res;
}
class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s3.size()!=(s1.size()+s2.size()))
        {
            return false;
        }
        
        for(int i=0;i<=s1.size();i++)
        {
            for(int j=0;j<=s2.size();j++)
            {
                dp[i][j]=-1;
            }
        }
        return dfs(s1,s2,s3,0,0,0);
    }
};
