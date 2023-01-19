class Solution 
{
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>sum(n+1,0);
    
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            sum[i]=(sum[i]%k +k)%k;
        }
        unordered_map<int,int>mp;
        mp[0]++;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int d=sum[i];
            ans+=mp[d];
            mp[d]++;
        }
        return ans;
    }
};
