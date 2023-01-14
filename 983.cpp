//Method-1: 

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

//Method-2 : 


class Solution 
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size();
        vector<int>dp(400,0);
        set<int>st(days.begin(),days.end());
        for(int i=1;i<366;i++)
        {
            if(st.find(i)==st.end())
            {
                dp[i]=dp[i-1];
            }
            else
            {
                int a=dp[i-1]+costs[0];
                int b=dp[max(0,i-7)]+costs[1];
                int c=dp[max(0,i-30)]+costs[2];
                dp[i]=min(a,min(b,c));
            }
        }
        return dp[365];
    }
};
