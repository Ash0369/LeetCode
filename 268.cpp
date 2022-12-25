//Method-1 : 
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++)
        {
            if(i==nums.size())
                return i;
            if(nums[i]!=i)
                return i;
        }
        return 0;
    }
};

//Method-2 : 

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=n*(n+1)/2;//Total sum
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr=curr+nums[i];
        }
        return sum-curr;
    }
};

//Method-3 : 
//https://leetcode.com/problems/missing-number/discuss/798483/Easy-solution-with-explanation
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int need=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr=curr^nums[i];
            need=need^(i+1);
        }
        return need^curr;
    }
};
