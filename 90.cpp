vector<vector<int>>result;
void reverse(vector<int>&nums,vector<int>&sub,int index)
{
    if(index>=nums.size())
    {
        result.push_back(sub);
        return;
    }
    sub.push_back(nums[index]);
    reverse(nums,sub,index+1);
    int temp=nums[index];
    sub.pop_back();
    while(index<nums.size() && nums[index]==temp)
    {
        index++;
    }
    reverse(nums,sub,index);
}
class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        result.clear();
        sort(nums.begin(),nums.end());
        vector<int>sub;
        reverse(nums,sub,0);
        return result;
    }
};
