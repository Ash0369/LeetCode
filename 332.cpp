void dfs(string s,  map<string,priority_queue<string,vector<string>,greater<string>>>&out,vector<string>&ans)
{
    while(!out[s].empty())
    {
        string node=out[s].top();
        out[s].pop();
        dfs(node,out,ans);
    }
    //We have to push after dfs if we put it before then it will give incorect 
    //As might be chance destination comes before but
    ans.push_back(s);
}
class Solution 
{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        map<string,priority_queue<string,vector<string>,greater<string>>>out;
        for(auto x:tickets)
        {
            out[x[0]].push(x[1]);
        }
        vector<string>ans;
        dfs("JFK",out,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
