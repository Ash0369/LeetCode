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


//Method-2 : 

#define ll long long
int find(int curr,vector<int>&start)
{
    int ind=lower_bound(start.begin(),start.end(),curr)-start.begin();
    return ind;
}
ll int taxi(vector<vector<int>>& rides,int curr,vector<ll int>&dp, vector<int>&start)
{
    int n=rides.size();
    if(curr==n)
        return 0;
    if(dp[curr]!=-1)
    {
        return dp[curr];
    }
    ll int not_pick=taxi(rides,curr+1,dp,start);
    ll int pick=0;
    int dest=find(rides[curr][1],start);
    pick=rides[curr][1]-rides[curr][0]+rides[curr][2]+ taxi(rides,dest,dp,start);

    return dp[curr]=max(pick,not_pick);
    
}

class Solution 
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        sort(rides.begin(),rides.end());
        vector<int>start;
        for(auto x:rides)
        {
            start.emplace_back(x[0]);
        }
        vector<ll int>dp(rides.size()+1,-1);
        return taxi(rides,0,dp,start);
    }
};


//Method-3 :

#define ll long long
int find(int curr,vector<int>&start)
{
    int ind=lower_bound(start.begin(),start.end(),curr)-start.begin();
    return ind;
}
class Solution 
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        sort(rides.begin(),rides.end());
        vector<int>start;
        for(auto x:rides)
        {
            start.emplace_back(x[0]);
        }
        int len=rides.size();
        vector<ll int>dp(len+1);
        vector<ll int>mdp(len+1);//Max value of dp in suffix
        dp[len]=0;
        mdp[len]=0;
        for(int i=len-1;i>=0;i--)
        {
            int dest=find(rides[i][1],start);
            ll int benefit=0;
            dp[i]=mdp[dest]+rides[i][1]-rides[i][0]+rides[i][2];
            mdp[i]=max(dp[i],mdp[i+1]);
        }
        return mdp[0];
    }
};
