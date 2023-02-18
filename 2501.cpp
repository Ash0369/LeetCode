#define ll long long
class Solution 
{
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,0);
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        int ans=0;
        for(ll int i=0;i<n;i++)
        {
            ll int start=nums[i];
            if(dp[i]==1)
            {
                continue;
            }
            int cnt=0;
            while(true)
            {
                if((start)>(nums[n-1]))
                {
                    break;
                }
                if(mp.find(start)==mp.end())
                {
                    break;
                }
                cnt++;
                dp[mp[start]]=1;
                start=start*start;
            }
            ans=max(ans,cnt);
        }
        if(ans==1 || ans==0)
        {
            return -1;
        }
        return ans;
    }
};
