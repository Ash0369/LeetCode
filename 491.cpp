set<vector<int>>ans;
void generate(int index,vector<int>&nums,int last,vector<int>&curr)
{
    
    if(index==nums.size())
    {
        if(curr.size()>1)
        {
            ans.insert(curr);
        }
        return;
    }
    generate(index+1,nums,last,curr);
    if(last==-1)
    {
        curr.push_back(nums[index]);
        generate(index+1,nums,index,curr);
        curr.pop_back();
    }
    else
    {
        if(nums[index]>=nums[last])
        {
            curr.push_back(nums[index]);
            generate(index+1,nums,index,curr);
            curr.pop_back();
        }
    }
}
class Solution 
{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        ans.clear();
        vector<int>curr;
        generate(0,nums,-1,curr);
        vector<vector<int>>ele;
        for(auto x:ans)
        {
            ele.push_back(x);
        }
        return ele;
    }
};
