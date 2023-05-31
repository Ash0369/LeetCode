#define ll long long
ll int ans=-1000;
void dfs(int index,vector<int>&nums,bool pick,ll int pro)
{
    if(index==nums.size())
    {
        if(pick)
        {
            ans=max(ans,pro);
        }
        return;
    }
    dfs(index+1,nums,pick,pro);
    
    dfs(index+1,nums,true,pro*nums[index]);
}
class Solution 
{
public:
    long long maxStrength(vector<int>& nums) 
    {
        ans=-1e15;
        dfs(0,nums,false,1);
        return ans;
    }
};
