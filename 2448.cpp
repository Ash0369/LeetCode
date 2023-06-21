#define ll long long
bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[0]<v2[0])
    {
        return true;
    }
    return false;
}
class Solution 
{
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        int n=nums.size();
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],cost[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<ll int>prefix(n+1,0);
        vector<ll int>suffix(n+1,0);
        ll int tot=vec[0][1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+tot*(vec[i][0]-vec[i-1][0]);
            tot+=vec[i][1];
        }
        ll int ans=prefix[n-1];
        tot=vec[n-1][1];
        for(int i=n-2;i>=0;i--)
        {
            ll int temp=prefix[i]+suffix[i+1]+(tot*(vec[i+1][0]-vec[i][0]));
            ans=min(ans,temp);
            tot+=vec[i][1];
            suffix[i]=temp-prefix[i];
        }
        return ans;
    }
};
