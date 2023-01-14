int cost(vector<int>& days, vector<int>& costs,int index,int have,vector<vector<int>>&dp)
{
    if(index==days.size())
        return 0;
    if(dp[index][have]!=-1)
        return dp[index][have];
    if(days[index]<=have)
    {
        return cost(days,costs,index+1,have,dp);   
    }
    int a=costs[0]+cost(days,costs,index+1,days[index],dp);
    int b=costs[1]+cost(days,costs,index+1,days[index]+6,dp);
    int c=costs[2]+cost(days,costs,index+1,days[index]+29,dp);
    
    return dp[index][have]=min(a,min(b,c));
}
class Solution 
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size();
        vector<vector<int>>dp(n,vector<int>(400,-1));
        return cost(days,costs,0,0,dp);
    }
};
