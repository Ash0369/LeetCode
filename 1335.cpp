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


//Method-2 : Memoization


int diff(vector<int>& job,int d,int index,vector<vector<int>>&dp)
{
    if(d==1)
    {
        int ele=0;
        for(int i=index;i<job.size();i++)
        {
            ele=max(ele,job[i]);
        }
        return dp[index][1]=ele;
    }
    if(dp[index][d]!=-1)
        return dp[index][d];
    int grt=0;
    int ans=INT_MAX;
    for(int i=index;job.size()-i>=d;i++)
    {
        grt=max(grt,job[i]);  
        ans=min(ans, grt+diff(job,d-1,i+1,dp));
    }
    
    return dp[index][d]=ans;
}
class Solution 
{
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        int sum=0;
        int n=jobDifficulty.size();
        
        vector<vector<int>>dp(n+1,vector<int>(11,-1));
        int ans=diff(jobDifficulty,d,0,dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};


//Method-3 : Tabulation

class Solution 
{
public:
    int minDifficulty(vector<int>& job, int d) 
    {
        int sum=0;
        int n=job.size();
        
        vector<vector<int>>dp(n+1,vector<int>(11,-1));

        for(int index=n-1;index>=0;index--)
        {
            for(int j=1;j<=d;j++)
            {
                if(j==1)
                {
                    int ele=0;
                    for(int i=index;i<job.size();i++)
                    {
                        ele=max(ele,job[i]);
                    }
                    dp[index][1]=ele;
                }
                else
                {
                    int grt=0;
                    int ans=INT_MAX;
                    for(int i=index;job.size()-i>=j;i++)
                    {
                        grt=max(grt,job[i]);  
                        ans=min(ans, grt+dp[i+1][j-1]);
                    }
                    dp[index][j]=ans;
                }
            }
        }
        if(dp[0][d]==INT_MAX)
            return -1;
        return dp[0][d];
    }
};
