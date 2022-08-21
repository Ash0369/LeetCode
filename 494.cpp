//Method-1 : (Not standard one of making target==0)

int ways(vector<int>&nums,int target,int index,int curr)
{
    if(index==0)
    {
        if(curr+nums[0]==target  && curr-nums[0]==target)
        {
            return 2;
        }
        else if(curr+nums[0]==target  || curr-nums[0]==target)
        {
            return 1;
        }
        return 0;
    }
    int a=ways(nums,target,index-1,curr+nums[index]);
    int b=ways(nums,target,index-1,curr-nums[index]);

    return a+b;
}
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return ways(nums,target,nums.size()-1,0);
    }
};

//Method-2 : 

int ways(vector<int>&nums,int target,int index)
{
    if(index==0)
    {
        if(target+nums[0]==0  && target-nums[0]==0)
        {
            return 2;
        }
        else if(target+nums[0]==0  || target-nums[0]==0)
        {
            return 1;
        }
        return 0;
    }
    int a=ways(nums,target+nums[index],index-1);
    int b=ways(nums,target-nums[index],index-1);

    return a+b;
}
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return ways(nums,target,nums.size()-1);
    }
};

//Method-3 : 
