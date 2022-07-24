class Solution 
{
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int n=edges.size()+1;
        vector<int>count(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            for(auto x:edges[i])
            {
                count[x]++;
            }
        }
        for(int i=0;i<count.size();i++)
        {
            if(count[i]==n-1)
            {
                return i;
            }
        }
        return 0;
    }
};
