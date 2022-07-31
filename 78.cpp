//Method-1 : Bit Manuplation

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>sol;
        int s=nums.size();
        int count=1<<s;
        for(int i=0;i<count;i++)
        {
            vector<int>sub;
            for(int j=0;j<s;j++)
            {
                int temp=1<<j;
                int res=temp&i;
                if(res!=0)
                {
                    sub.push_back(nums[j]);
                }
            }
            sol.push_back(sub);
        }
        return sol;
    }
};

//Method-2 : recurssion

vector<vector<int>>result;
void subset(vector<int>&nums,int index,vector<int>sub)
{
    if(index==nums.size())
    {
        result.push_back(sub);
        return;
    }
    subset(nums,index+1,sub);
    sub.push_back(nums[index]);
    subset(nums,index+1,sub);
}
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        result.clear();
        vector<int>sub;
        subset(nums,0,sub);
        return result;
    }
};

//Method-3 : passing by refernce

vector<vector<int>>result;
void subset(vector<int>&nums,int index,vector<int>&sub)
{
    if(index==nums.size())
    {
        result.push_back(sub);
        return;
    }
    subset(nums,index+1,sub);
    sub.push_back(nums[index]);
    subset(nums,index+1,sub);
    sub.pop_back();
}
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        result.clear();
        vector<int>sub;
        subset(nums,0,sub);
        return result;
    }
};
