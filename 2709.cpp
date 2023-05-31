int dfs(int index,vector<vector<int>>&graph,vector<int>&dp,int n)
{
    int cnt=0;
    dp[index]=1;
    if(index<=n)
    {
        cnt++;
    }
    for(auto x:graph[index])
    {
        if(dp[x]==1)
        {
            continue;
        }
        cnt+=dfs(x,graph,dp,n);
    }
    return cnt;
}
const int primes[65]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 
    227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
class Solution 
{
public:
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        int n=nums.size();
        int base=n;
        int mx=0;
        for(auto x:nums)
        {
            mx=max(mx,x);
        }
        vector<vector<int>>graph(n+mx+1);
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            for(auto j:primes)
            {
                if(ele%j==0)
                {
                     graph[j+base].push_back(i+1);
                     graph[i+1].push_back(j+base);
                     while(ele%j==0)
                     {
                         ele=ele/j;
                     }
                }
            }
            if(ele!=1)
            {
                graph[ele+base].push_back(i+1);
                graph[i+1].push_back(ele+base);
            }
        }
        vector<int>dp(n+mx+1,0);
        int cnt=dfs(1,graph,dp,n);
        return cnt==n;
    }
};
