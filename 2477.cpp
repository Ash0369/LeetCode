#define ll long long
ll int cost=0;
int dfs(int point,vector<vector<int>>&graph,vector<bool>&dp,int seats)
{
    int person=1;
    dp[point]=true;
    for(auto x:graph[point])
    {
        if(dp[x]==true)
            continue;
        person+=dfs(x,graph,dp,seats);
    }
    int car=person/seats;
    if(person%seats!=0)
        car++;
    cost+=car;
    return person;
}
class Solution 
{
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        cost=0;
        int n=roads.size();
        vector<vector<int>>graph(n+1);
        for(auto x:roads)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<bool>dp(n+1,false);
        int person=dfs(0,graph,dp,seats);
        int car=person/seats;
        if(person%seats!=0)
            car++;
        cost-=car;//As in dfs 1 time extra cost is added to move further from 0
        return cost;
    }
};
