bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[0]<vec2[0])
        return true;
    if(vec1[0]==vec2[0])
    {
        if(vec1[1]<vec2[1])
            return true;
    }
    return false;
}
class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n=intervals.size();
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<=n;i++)
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
