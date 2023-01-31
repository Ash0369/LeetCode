//Method-1 : 

int team(vector<pair<int,int>>&vec,int index,int last,vector<vector<int>>&dp)
{
    int n=vec.size();
    if(index==n)
        return 0;
    if(last!=-1 && dp[index][last]!=-1)
        return dp[index][last];
    int not_pick=team(vec,index+1,last,dp);
    int pick=0;
    int last_age=(last!=-1) ? vec[last].second : 0;
    int last_score=(last!=-1) ? vec[last].first : 0;
    if(last_age==vec[index].second || (vec[index].first>=last_score))
    {
        pick=vec[index].first+team(vec,index+1,index,dp);
    }
    int ans=max(pick,not_pick);
    return (last!=-1)? dp[index][last]=ans : ans ;
}
bool cmp(pair<int,int>&p1,pair<int,int>&p2)
{
    if(p1.second<p2.second)
        return true;
    if(p1.second==p2.second && p1.first<p2.first)
        return true;
    return false;
}
class Solution 
{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<ages.size();i++)
        {
            vec.push_back({scores[i],ages[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        int n=ages.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return team(vec,0,-1,dp);
    }
};


//Method-2 : 

bool cmp(pair<int,int>&p1,pair<int,int>&p2)
{
    if(p1.second<p2.second)
        return true;
    if(p1.second==p2.second && p1.first<p2.first)
        return true;
    return false;
}
class Solution 
{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<ages.size();i++)
        {
            vec.emplace_back(scores[i],ages[i]);
        }
        sort(vec.begin(),vec.end(),cmp);
        int n=ages.size();
        vector<int>dp(n);
        
        for(int i=0;i<n;i++)
        {
            dp[i]=vec[i].first;
            int mx=0;
            for(int j=i-1;j>=0;j--)
            {
                if(dp[i]>=vec[j].first)
                    mx=max(mx,dp[j]);
            }
            dp[i]+=mx;
        }
        sort(dp.begin(),dp.end());
        return dp[n-1];
    }
};
