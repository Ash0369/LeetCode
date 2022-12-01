class Solution 
{
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        int n=recipes.size();
        unordered_map<string,vector<string>>mp;
        unordered_map<string,int>indegree;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                mp[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        vector<string>ans;
        queue<string>q;
        for(auto x:supplies)
            q.push(x);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            for(auto x:mp[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    ans.push_back(x);
                    q.push(x);
                }
            }
        }
        return ans;
    }
};
