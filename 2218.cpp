int dp[1001][2001];
int find(int i,vector<vector<int>>& piles,int k)
{
    if(k==0)
    {
        return 0;
    }
    if(i==piles.size())
    {
        return -1*2000;
    }
    if(dp[i][k]!=-1)
    {
        return dp[i][k];
    }
    int score_pick=find(i+1,piles,k);
    int score_not=0;
    for(int j=0;j<piles[i].size() && k-j-1>=0;j++)
    {
        score_not=max(score_not,piles[i][j]+find(i+1,piles,k-j-1));
    }
    return dp[i][k]=max(score_pick,score_not);
}
class Solution 
{
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<piles[i].size();j++)
            {
                if(j==0)
                {
                    continue;
                }
                piles[i][j]+=piles[i][j-1];
            }
        }
        return find(0,piles,k);
    }
};
