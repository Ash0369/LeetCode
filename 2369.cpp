//Method-1 : 

bool divide(vector<int>&nums,int index,int last,vector<vector<int>>&dp)
{
    int n=nums.size();
    if(index>=n)
    {
        if(last==0)
        {
            return true;
        }
        return false;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    if(last==0)
    {
        return divide(nums,index+1,1,dp);
    }
    bool a=false;
    bool b=false;
    bool c=false;
    if(nums[index-1]==nums[index])
    {
        a=divide(nums,index+1,0,dp);
        if(index+1<n && nums[index+1]==nums[index])
        {
            b=divide(nums,index+2,0,dp);
        }
            
       
    }
    else if(nums[index-1]==nums[index]-1)
    {
        if(index+1<n && nums[index+1]==1+nums[index])
        {
            c=divide(nums,index+2,0,dp);
        }
    }
    
    
    return dp[index][last]=(a|b)|c;
    
}
class Solution 
{
public:
    bool validPartition(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return divide(nums,0,0,dp);
    }
};


//Method-2 : 

class Solution 
{
public:
    bool validPartition(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool>dp(n+1,false);
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                if(i-2<0 || dp[i-2]==true)
                {
                    dp[i]=true;
                }
            }
            if(i>=2 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2])
            {
                if(i-3<0 || dp[i-3]==true)
                {
                    dp[i]=true;
                }
            }
            if(i>=2 && nums[i]==1+nums[i-1] && nums[i-1]==1+nums[i-2])
            {
                if(i-3<0 || dp[i-3]==true)
                {
                    dp[i]=true;
                }
            }
        }
        return dp[n-1];
    }
};
