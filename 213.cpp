//Method-1 : Memoization


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
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>new_vec;
        for(int i=1;i<nums.size();i++)
        {
            new_vec.push_back(nums[i]);
        }
        vector<int>dp(new_vec.size(),-1);
        int a=robber(new_vec,dp,new_vec.size()-1); //Robbing from 1 to n

        nums.pop_back();
        vector<int>dp2(nums.size(),-1);

        int b=robber(nums,dp2,nums.size()-1);

        return max(a,b);
        
    }
};


//Method-2 : Tabulation


int robber(vector<int>& nums) 
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
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
         if(nums.size()==1)
         {
             return nums[0];
         }
        vector<int>temp;
        for(int i=1;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        int a=robber(temp);
        nums.pop_back();
        int b=robber(nums);
        return max(a,b);
        
    }
};

//Method-3 : Space Optimization

int robber(vector<int>& nums) 
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
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>temp;
        for(int i=1;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        int a=robber(temp);
        nums.pop_back();
        int b=robber(nums);
        return max(a,b);
    }
};
