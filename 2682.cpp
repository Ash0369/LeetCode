class Solution 
{
public:
    vector<int> circularGameLosers(int n, int k) 
    {
        set<int>st;
        int curr=1;
        int iter=1;
        st.insert(1);
        while(true)
        {
            curr=curr+(k*iter);
            curr=curr%(n);
            if(st.find(curr)!=st.end())
            {
                break;
            }
            st.insert(curr);
            iter++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
            {
                if(i==0)
                {
                    ans.push_back(n);
                    continue;
                }
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
