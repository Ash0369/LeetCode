bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[1]<vec2[1])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    int findMinimumTime(vector<vector<int>>& tasks) 
    {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),cmp);
        vector<bool>dp(2005,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int duration=tasks[i][2];
            int end=tasks[i][1];
            int start=tasks[i][0];
            int available=0;
            for(int j=start;j<=end;j++)
            {
                if(dp[j]==true)
                {
                    available++;
                }
            }
            if(available>=duration)
            {
                continue;
            }
            for(int j=end;j>=start;j--)
            {
                if(dp[j]==false)
                {
                    dp[j]=true;
                    available++;
                    ans++;
                }
                if(available>=duration)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
