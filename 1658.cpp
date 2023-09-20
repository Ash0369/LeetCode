class Solution 
{
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        map<int,vector<int>>mp;
        mp[0].push_back(0);
        mp[0].push_back(n);
        int curr=0;
        curr=0;
        for(int i=n-1;i>=0;i--)
        {
            curr+=nums[i];
            mp[curr].push_back(i);
        }
        curr=0;
        int ans=1e9;
        for(int i=0;i<=n;i++)
        {
            if(i==0)
            {
                int check=x-curr;
                for(auto x:mp[check])
                {
                    
                    ans=min(ans,i+n-x);
                }
                continue;
            }
            curr+=nums[i-1];
            int check=x-curr;
            for(auto x:mp[check])
            {
                if(x<=i-1)
                {
                    continue;
                }
                ans=min(ans,i+n-x);
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};
