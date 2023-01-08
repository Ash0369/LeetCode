//Method-1 : 


int mx(vector<int>&nums,int index,int mod,vector<vector<int>>&dp)
{
    if(index==nums.size())
    {
        if(mod==0)
            return 0;
        return -1;
    }
    if(dp[index][mod]!=-1)
        return dp[index][mod];
    int pick=mx(nums,index+1,(mod+(nums[index])%3)%3,dp);
    int not_pick=mx(nums,index+1,mod,dp);
    
    if(pick!=-1)
        pick+=nums[index];
    
    return dp[index][mod]=max(pick,not_pick);
}
class Solution 
{
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return max(0,mx(nums,0,0,dp));
    }
};


//Method-2 : 


class Solution 
{
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(3,0));
        //dp[i][j]--> Max sum till ith index if mod is j
        dp[0][0]=0;
        dp[0][1]=-1;
        dp[0][2]=-1;
        for(int i=1;i<=n;i++)
        {
            int r=nums[i-1]%3;
            for(int j=0;j<=2;j++)
            {
                int pick=-1;
                int not_pick=dp[i-1][j];
                
                for(int k=0;k<=2;k++)
                {
                    if((k+r)%3==j && dp[i-1][k]!=-1)
                    {
                        pick=nums[i-1]+dp[i-1][k];
                        break;
                    }
                }
                
                dp[i][j]=max(pick,not_pick);
            }
            
        }
        return dp[n][0];
    }
};
