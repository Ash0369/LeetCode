class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int remove=0;
        int minend=INT_MIN;
        int cnt=0;
        for(auto x:intervals)
        {
            if(x[0]>=minend)
            {
                minend=x[1];
                remove+=cnt;
                cnt=0;
            }
            else
            {
                cnt++;
                minend=min(minend,x[1]);
            }
        }
        remove+=cnt;
        return remove;
    }
};
