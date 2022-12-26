//Method-1 : 

bool jump(vector<int>&nums,int index,vector<int>&dp)
{
    if(index>=(nums.size()-1))
        return dp[index]=true;
    
    if(dp[index]!=-1)
        return dp[index];
    for(int i=1;i<=nums[index];i++)
    {
        if(jump(nums,index+i,dp))
            return dp[index]=true;
    }
    return dp[index]=false;
}
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return jump(nums,0,dp);
    }
};

//Method-2 : 

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool>dp(n+1,false);
        //dp[i]-->If it possible to reach ith step or not
        dp[0]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==true && nums[j]>=(i-j))
                {
                    dp[i]=true;
                    break;
                }
            }
            
        }
        return dp[n-1];
    }
};
