#define ll long long
ll int ans;
int bit=64;
ll int dfs(int index,vector<int>&skill,int curr,int &req,vector<vector<ll int>>&dp)
{
    
    int r=curr;
    if(index==skill.size())
    {
        if(req==curr)
        {
            return 0;
        }
        return -1;
    }
    if(dp[index][curr]!=-2)
    {
        return dp[index][curr];
    }
    ll int ans1=dfs(index+1,skill,curr,req,dp);
    int num=skill[index];
    curr=curr|num;
    ll int ans2=dfs(index+1,skill,curr,req,dp);
    if(ans2==-1)
    {
        return dp[index][r]=ans1;
    }
   
    ans2=ans2|(1LL<<(index+1));
    if(ans1==-1)
    {
        return dp[index][r]=ans2;
    }
    if(ans2==-1)
    {
        return  dp[index][r]=ans1;
    }
    int n1=__builtin_popcountll(ans1);
    int n2=__builtin_popcountll(ans2);
    if(n1<=n2)
    {
        return dp[index][r]=ans1;
    }
    return dp[index][r]=ans2;
}
class Solution 
{
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        map<string,int>mp;
        int i=0;
        int req=0;
        for(auto x:req_skills)
        {
            req=req|(1<<i);
            mp[x]=i;
            i++;
        }
        vector<int>skill;
        for(int i=0;i<people.size();i++)
        {
            int num=0;
            for(auto x:people[i])
            {
                if(mp.find(x)==mp.end())
                {
                    continue;
                }
                int c=mp[x];
                num=num|(1<<c);
            }
            skill.push_back(num);
        }
        vector<vector<ll int>>dp(people.size()+1,vector<ll int>(65538,-2));
        ll int ans=dfs(0,skill,0,req,dp);
        cout<<ans<<endl;
        vector<int>res;
        int bit=0;
        while(ans>0)
        {
            if((ans&1)>0)
            {
                res.push_back(bit-1);
            }
            bit++;
            ans=ans>>1;
        }
        return res;
    }
};
