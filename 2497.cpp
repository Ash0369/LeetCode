class Solution 
{
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) 
    {
        int n=vals.size();
        vector<vector<int>>graph(n);
        for(auto x:edges)
        {
           
            graph[x[0]].push_back(vals[x[1]]);
            graph[x[1]].push_back(vals[x[0]]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<int>vec=graph[i];
            sort(vec.begin(),vec.end(),greater<int>());
            int curr=vals[i];
            int iter=0;
            for(auto x:vec)
            {
                if(iter==k)
                    break;
                curr=curr+max(0,x);
                iter++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};
