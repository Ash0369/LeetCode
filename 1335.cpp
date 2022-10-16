//Method-1 : Brute Force will give TLE for large Test Cases



int ans=INT_MAX;
void diff(vector<int>& job,int d,int index,int sum)
{
    if(d==1)
    {
        int ele=0;
        for(int i=index;i<job.size();i++)
        {
            ele=max(ele,job[i]);
        }
        ans=min(ans,sum+ele);
        return;
    }
    int grt=0;
    for(int i=index;job.size()-i>=d;i++)
    {
        grt=max(grt,job[i]);  
        diff(job,d-1,i+1,sum+grt);
    }
}
class Solution 
{
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        ans=INT_MAX;
        diff(jobDifficulty,d,0,0);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
