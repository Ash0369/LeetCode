class Solution 
{
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {
        vector<vector<int>>q;
        int i=0;
        for(auto x:queries)
        {
            int a=x[0];
            int b=x[1];
            q.push_back({max(a,b),min(a,b),i});
            i++;
        }
        sort(q.begin(),q.end());
        reverse(q.begin(),q.end());
        set<pair<int,int>>st;
        int n=heights.size();
        int start=n-1;
        int sz=queries.size();
        vector<int>ans(sz);
        for(auto x:q)
        {
            
            int p1=x[0];
            int p2=x[1];
            int index=x[2];
            if(p1==p2)
            {
                ans[index]=p1;
                continue;
            }
            while(start>=p1)
            {
                st.insert({heights[start],start});
                auto lb=st.upper_bound({heights[start],-1});
                queue<pair<int,int>>q;
                while(true)
                {
                    if((*lb).second>start)
                    {
                        q.push(*lb);
                    }
                    if(lb==st.begin())
                    {
                        break;
                    }
                    lb--;
                }
                while(!q.empty())
                {
                    st.erase(q.front());
                    q.pop();
                }
                start--;
            }
            
            if(heights[p1]>heights[p2])
            {
                ans[index]=p1;
                continue;
            }
            auto lb=st.lower_bound({max(heights[p1],heights[p2])+1,-1});
            if(lb==st.end())
            {
                ans[index]=-1;
            }
            else{
                queue<pair<int,int>>q;
                int h=(*lb).first;
                int pos=(*lb).second;
                int mn=pos;
               
                pos=mn;
                ans[index]=pos;
                st.insert({h,pos});
            }
        }
        return ans;
    }
};
