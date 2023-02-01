//Method-1 : Brute Force DP Will give TLE


int taxi(vector<vector<int>>& rides,int curr,int last,vector<vector<int>>&dp)
{
    if(curr==rides.size())
        return 0;
    if(last!=-1 && dp[curr][last]!=-1)
    {
        return dp[curr][last];
    }
    if(last!=-1 && rides[last][1]<=rides[curr][0])
    {
        last=-1;
    }
    int not_pick=taxi(rides,curr+1,last,dp);
    int pick=0;
    if(last==-1)
    {
        pick=rides[curr][1]-rides[curr][0]+rides[curr][2]+taxi(rides,curr+1,curr,dp);
    }
    int val=max(pick,not_pick);
    if(last==-1)
        return val;
    return dp[curr][last]=val;
    
}
class Solution 
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        sort(rides.begin(),rides.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return taxi(rides,0,-1,dp);
    }
};
