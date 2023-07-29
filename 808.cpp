map<pair<int,int>,double>mp;

double dfs(int a,int b)
{
    if(a<=0 && b<=0)
    {
        return 0.5;
    }
    if(a<=0)
    {
        return 1;
    }    
    if(b<=0)
    {
        return 0;
    }
    if(mp.find({a,b})!=mp.end())
    {
        return mp[{a,b}];
    }
    double ans=0;
    
    ans+=dfs(a-100,b);
    ans+=dfs(a-75,b-25);
    ans+=dfs(a-50,b-50);
    ans+=dfs(a-25,b-75);
    
    return mp[{a,b}]=ans/(double)4;
}
class Solution 
{
public:
    double soupServings(int n) 
    {
        if(n>=5000)
        {
            return 1.0;
        }
        mp.clear();
        return dfs(n,n);
    }
};
