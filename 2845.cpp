#define ll long long
class Solution 
{
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        int n=nums.size();
        vector<int>pre(n+5,0);
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                pre[i]=pre[i-1];
                
            }
            if(nums[i]%modulo==k)
            {
                pre[i]++;
            }
            mp[pre[i]%modulo]++;
        }
        ll int ans=0;
        int k1=k;
        for(int i=0;i<n;i++)
        {
            ans+=mp[k1];
            if(nums[i]%modulo==k)
            {
                k1=(k1+1)%modulo;
            }
             mp[pre[i]%modulo]--;
            
        }
        return ans;
    }
};
