int ans=1;
void dfs(int index,int d,vector<int>&arr, map<int,vector<int>>&mp,int curr,vector<int>&dp)
{
    
    ans=max(ans,curr);
    if(index>=arr.size())
    {
        return;
    }
    if(dp[index]!=-1)
    {
        if(dp[index]>=curr)
        {
            return;
        }
    }
    if(mp[arr[index]+d].size()!=0)
    {
       
        int index1= upper_bound(mp[arr[index]+d].begin(), mp[arr[index]+d].end(),index)-mp[arr[index]+d].begin();
        if(index1<mp[arr[index]+d].size())
        {
            dfs(mp[arr[index]+d][index1],d,arr,mp,curr+1,dp);
        }
        
    }
    dfs(index+1,d,arr,mp,1,dp);
    dp[index]=curr;
}
class Solution
{
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        ans=1;
        vector<int>dp(arr.size()+2,-1);
        dfs(0,difference,arr,mp,1,dp);
        return ans;
    }
};
