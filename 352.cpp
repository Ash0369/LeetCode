class SummaryRanges 
{
public:
    set<int>st;
    SummaryRanges() 
    {
    }
    
    void addNum(int value) 
    {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() 
    {
        int prev=-1;
        vector<vector<int>>ans;
        vector<int>curr;
        
        for(auto x:st)
        {
            if(prev==-1)
            {
                prev=x;
                curr.push_back(x);
            }
            else if(prev==x-1)
            {
                prev=x;
            }
            else
            {
                curr.push_back(prev);
                ans.push_back(curr);
                curr.clear();
                prev=x;
                curr.push_back(x);
            }
        }
        
        if(!curr.empty())
        {
            curr.push_back(prev);
            ans.push_back(curr);
        }
        return ans;
        
    }
    
};
