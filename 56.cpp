class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++)
        {
            if(!ans.empty())
            {
                auto ele=ans.back();
                if(intervals[i][0]<=ele[1] && intervals[i][1]>ele[1])
                {
                    int start=ele[0];
                    int end=intervals[i][1];
                    ans.pop_back();
                    ans.push_back({start,end});
                }
                else if(intervals[i][0]<=ele[1] && intervals[i][1]<=ele[1])
                {
                    continue;
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
