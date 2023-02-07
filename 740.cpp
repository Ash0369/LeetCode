int earn(int index,map<int,int>&score,vector<int>&nums,vector<int>&dp)
{
    int n=nums.size();
    
    if(index==n)
        return 0;
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    //Not perform delete
    int a=earn(index+1,score,nums,dp);
    //perform delete;
    int b=nums[index]*score[nums[index]];
    
    int new_index=index+1;
    while(new_index<n && nums[new_index]==(nums[index]+1))
    {
        new_index++;
    }
    b+=earn(new_index,score,nums,dp);
    
    return dp[index]=max(a,b);
}
class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        map<int,int>mp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        nums.clear();
        for(auto x:mp)
        {
            nums.emplace_back(x.first);
        }
        return earn(0,mp,nums,dp);
    }
};
