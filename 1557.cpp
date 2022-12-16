vector<int>parent;
int find(int x)
{
    if(parent[x]==-1)
        return x;
    return parent[x]=find(parent[x]);
}
class Solution 
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        parent.clear();
        parent.resize(n+1,-1);
        for(auto x:edges)
        {
            parent[x[1]]=find(x[0]);
        }
        vector<int>st;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i || parent[i]==-1)
                st.push_back(i);
        }
        return st;
    }
};
