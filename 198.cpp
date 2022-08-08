//Method-1 : Time Complexity O(n) and Space Complexity O(n) and Auxillary Space O(n)


int robber(vector<int>&nums,vector<int>&dp,int index)
{
    if(index==0)
    {
        dp[0]=nums[0];
        return nums[0];

    }
    if(index==1)
    {
        dp[1]=max(nums[0],nums[1]);
        return dp[1];
    }
    if(dp[index]==-1)
    {
        int picked=nums[index]+robber(nums,dp,index-2);
        int not_picked=robber(nums,dp,index-1);
        dp[index]=max(picked,not_picked);
    }
    return dp[index];
}
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size(),-1);
        return robber(nums,dp,nums.size()-1);
    }
};


//Method-2 : Space Complexity O(n)

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            int a=nums[i]+dp[i-2];
            int b=dp[i-1];
            dp[i]=max(a,b);
        }
        return dp[nums.size()-1];
    }
};

//Method-3 : Space Complexity : O(1)

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        int a=nums[0];
        int b=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            int c=nums[i]+a;
            int d=max(c,b);
            a=b;
            b=d;
        }
        return b;
    }
};
