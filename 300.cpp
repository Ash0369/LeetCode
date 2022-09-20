//Method-1 : Memoization

int longest(vector<int>&nums,int index,int prev,vector<vector<int>>&dp)
{
    if(index==nums.size())
        return 0;
    
    if(dp[index][prev+1]==-1)
    {
        int pick=0;
        if(prev==-1 || nums[index]>nums[prev])
            pick=1+longest(nums,index+1,index,dp);
        
        int not_pick=longest(nums,index+1,prev,dp);
        
        dp[index][prev+1]=max(pick,not_pick);
    }
    return dp[index][prev+1];
}
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return longest(nums,0,-1,dp);
    }
};


//Method-2 : Tabulation


class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int pick=0;
                if(prev==-1 || nums[index]>nums[prev])
                    pick=1+dp[index+1][index+1];
                
                
                int not_pick=dp[index+1][prev+1];
                
                dp[index][prev+1]=max(pick,not_pick);
            }
        }
        return dp[0][0];
    }
};
