//Method-1 : 

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


//Method-2 : 

class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        map<int,int>mp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1);
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        nums.clear();
        for(auto x:mp)
        {
            nums.emplace_back(x.first);
        }
        dp[nums.size()]=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            //Not pick 
            dp[i]=dp[i+1];
            
            //pick
            int new_index=i+1;
            while(new_index<nums.size() && nums[new_index]==(nums[i]+1))
            {
                new_index++;
            }
            int val=(nums[i]*mp[nums[i]])+dp[new_index];
            dp[i]=max(dp[i],val);
        }
        
        return dp[0];
    }
};
