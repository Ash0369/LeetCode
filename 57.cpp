//Method-1 : 

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


//Method-2 : 

class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n=intervals.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(newInterval[0]>intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else if(newInterval[1]<intervals[i][0])
            {
                ans.push_back(newInterval);
                newInterval=intervals[i];
            }
            else if(intervals[i][1]>=newInterval[0] || intervals[i][0]<=newInterval[1])
            {
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        ans.push_back(newInterval); 
        return ans;
    }
};
