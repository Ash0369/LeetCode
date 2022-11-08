class Solution 
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n=values.size();
        map<string,vector<pair<string,double>>>mp;
        vector<double>ans;
        for(int i=0;i<n;i++)
        {
            string start=equations[i][0];
            string end=equations[i][1];
            
            double distance=values[i];
            mp[start].push_back({end,distance});
            mp[end].push_back({start,1/distance});
        }
        
        for(int i=0;i<queries.size();i++)
        {
            string startq=queries[i][0];
            string endq=queries[i][1];
            if(mp.find(startq)==mp.end() || mp.find(endq)==mp.end())
            {
                ans.push_back(-1);
                continue;
            }
            double value=0.0;
            queue<pair<string,double>>q;
            set<string>dp;
            q.push({startq,1.0});
            while(!q.empty())
            {
                auto node=q.front();
                q.pop();
                if(node.first==endq)
                {
                    value=node.second;
                    break;
                }
                
                for(auto it:mp[node.first])
                {
                    if(dp.find(it.first)!=dp.end())
                        continue;
                    q.push({it.first,it.second*node.second});
                    dp.insert(it.first);
                }
                    
            }
            
            if(value==0.0)
                ans.push_back(-1);
            else
                ans.push_back(value);
            
        }
        return ans;
    }
};
