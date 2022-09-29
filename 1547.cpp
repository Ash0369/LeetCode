//Method-1 : 

int cost(vector<int>& cuts,int low,int high,vector<vector<int>>&dp)
{
    if(low>high)
        return 0;
    if(dp[low][high]==-1)
    {
         int res=INT_MAX;
         for(int i=low;i<=high;i++)
         {
             int c=cuts[high+1]-cuts[low-1]+cost(cuts,low,i-1,dp)+cost(cuts,i+1,high,dp);
             res=min(res,c);
         }
         dp[low][high]=res;
    }
    return dp[low][high];
}
class Solution 
{
public:
    int minCost(int n, vector<int>& cuts) 
    {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return cost(cuts,1,c,dp);
    }
};


//Method-2 : 

int cost(vector<int>& cuts,int low,int high,vector<vector<int>>&dp)
{
    if(low>high)
        return 0;
    if(dp[low][high]==-1)
    {
         int res=INT_MAX;
         for(int i=low;i<=high;i++)
         {
             int c=cuts[high+1]-cuts[low-1]+cost(cuts,low,i-1,dp)+cost(cuts,i+1,high,dp);
             res=min(res,c);
         }
         dp[low][high]=res;
    }
    return dp[low][high];
}
class Solution 
{
public:
    int minCost(int n, vector<int>& cuts) 
    {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        
        for(int low=c;low>=1;low--)
        {
            for(int high=1;high<=c;high++)
            {
                if(low>high)
                    continue;
                int res=INT_MAX;
                for(int i=low;i<=high;i++)
                {
                     int c=cuts[high+1]-cuts[low-1]+dp[low][i-1]+dp[i+1][high];
                     res=min(res,c);
                }
                dp[low][high]=res;
            }
        }
        return dp[1][c];
    }
};
