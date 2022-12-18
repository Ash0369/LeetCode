class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        stack<pair<int,int>>st;
        st.push({temperatures[0],0});
        vector<int>ans(n,0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && temperatures[i]>st.top().first)
            {
                auto node=st.top();
                st.pop();
                ans[node.second]=i-node.second;
            }
            st.push({temperatures[i],i});
        }
        while(!st.empty())
        {
            auto node=st.top();
            st.pop();
            ans[node.second]=0;
        }
        return ans;
    }
};
