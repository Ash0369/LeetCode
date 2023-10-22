int dp2[101][101][101];
int n;
int dfs(int index,int prev,int k,int dp[][105])
{
    if(index==n)
    {
        if(k==0 && prev==n)
        {
            return 0;
        }
        return 1e9;
    }
    if(dp2[index][prev][k]!=-1)
    {
        return dp2[index][prev][k];
    }
    //take or skip it
    int a=dfs(index+1,prev,k,dp);
    
    //take it
    int b=1e9;
    if(k!=0)
    {
        b=dp[prev][index]+dfs(index+1,index+1,k-1,dp);
    }
    return dp2[index][prev][k]=min(a,b);
}
class Solution 
{
public:
    int palindromePartition(string s, int k) 
    {
        n=s.size();
        int dp[105][105];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                //How to make (i,j) as palindeome
                temp.push_back(s[j]);
                
                int p=j;
                int y=i;
                int cnt=0;
                while(y<p)
                {
                    if(s[y]!=s[p])
                    {
                        cnt++;
                    }
                    y++;
                    p--;
                }
                dp[i][j]=cnt;
            }
        }
        memset(dp2,-1,sizeof(dp2));
        return dfs(0,0,k,dp);
    }
};
