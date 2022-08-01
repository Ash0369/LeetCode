//Method1- Time Complexity : O(n!*n) and Space Complexity : O(n)+O(n) , Auxillary Space O(n)

vector<vector<int>>result;
void permutation(vector<int>&nums,vector<int>&per,vector<int>&visited)
{
    if(per.size()==nums.size())
    {
        result.push_back(per);
        return;
    }
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            per.push_back(nums[i]);
            permutation(nums,per,visited);
            visited[i]=0;
            per.pop_back();
        }
    }
}
class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        result.clear();
        vector<int>visited(nums.size(),0);
        vector<int>per;
        permutation(nums,per,visited);
        return result;
    }
};

//Method-2 : Time Complexity O(n!*n) , Space Complexity O(1) , Auxillary Space O(n)

vector<vector<int>>result;
void swap(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
    return;
}
void permutation(vector<int>&nums,int index)
{
    if(index==(nums.size()))
    {
        result.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++)
    {
        swap(nums[index],nums[i]);
        permutation(nums,index+1);
        swap(nums[index],nums[i]);
    }
}
class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        result.clear();
        permutation(nums,0);
        return result;
    }
};
