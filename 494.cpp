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

//Method-3 : (Relating to DP Q s1-s2=d)

int ways(vector<int>&nums,int target,int index)
{
    if(index==0)
    {
        if(target==0 && nums[0]==0)
        {
            return 2;
        }
        else if(target==nums[0] || target==0)
        {
            return 1;
        }
        return 0;
    }
    int a=ways(nums,target-nums[index],index-1);
    int b=ways(nums,target,index-1);

    return a+b;
}
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        //We can divide nums in 2 subset s1,s2 such that s1-s2=target

        int sum=0;
        for(auto x:nums)
        {
            sum=sum+x;
        }
        if(target>sum)
        {
            return 0;
        }
        if((target+sum)%2!=0)
        {
            return 0;
        }

        int s1=(target+sum)/2;
        return ways(nums,s1,nums.size()-1);
    }
};

//Method-4 : (Memoization with help of map)

int ways(vector<int>&nums,int target,int index,map<pair<int,int>,int>&mp)
{
    if(index==0)
    {
        if(target==nums[0] && nums[0]==0)
        {
            return 2;
        }
        else if(target==nums[0] || target==0)
        {
            return 1;
        }
        return 0;
    }
    if(mp.find(make_pair(index,target))==mp.end())
    {
        int a=0;
        if(target>=nums[index])
        {
            a=ways(nums,target-nums[index],index-1,mp);
        }
        int b=ways(nums,target,index-1,mp);

        mp[make_pair(index,target)]=a+b;
    }

    return mp[make_pair(index,target)];
}
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        //We can divide nums in 2 subset s1,s2 such that s1-s2=target

        int sum=0;
        for(auto x:nums)
        {
            sum=sum+x;
        }
        if(target>sum)
        {
            return 0;
        }
        if((target+sum)%2!=0)
        {
            return 0;
        }

        int s1=(target+sum)/2;
        map<pair<int,int>,int>mp;
        return ways(nums,s1,nums.size()-1,mp);
    }
};
