void dfs(int ele,map<int,vector<int>>&outdegree,vector<vector<int>>&ans)
{
    if(outdegree.find(ele)==outdegree.end())
        return;
    while(!outdegree[ele].empty())
    {
         int node=outdegree[ele].back();
         outdegree[ele].pop_back();
         dfs(node,outdegree,ans);
         ans.push_back({ele,node});
    }
   
}
class Solution 
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        //It is clearly a question of Eulearian path.
        //As starting point will be previous ending point.
        //We can nevere come to that edge again.
        //And as we can't connect last and first so eulerain circuit is not possible.
        
        
        //Starting point will be node whose indegree will be more
        
        //Ending point  will have outdegree more
        
        
        map<int,int>indegree;
        map<int,vector<int>>outdegree;
        for(auto x:pairs)
        {
           outdegree[x[0]].push_back(x[1]);
           indegree[x[1]]++;
        }
        
        vector<vector<int>>ans;
        int ele=pairs[0][0]; //A default value must be given because if eulerian ckt
        //Then no one satisfy " if " condition. At that case any can be starting
        for(auto x:outdegree)
        {
            if(outdegree[x.first].size()==indegree[x.first]+1)
            {
                ele=x.first;
                break;
            }
        }
        dfs(ele,outdegree,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
