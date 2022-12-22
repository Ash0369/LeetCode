//Method-1

class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second>1)
                return x.first;
        }
        return -1;
    }
};

//Method-2:

//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/discuss/208317/C%2B%2B-2-lines-O(4)-or-O-(1)

class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};
