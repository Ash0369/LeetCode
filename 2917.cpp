class Solution 
{
public:
    int findKOr(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        for(auto x:nums)
        {
            int y=x;
            int b=0;
            while(y>0)
            {
                if((y&1))
                {
                    mp[b]++;
                }
                b++;
                y=y/2;
            }
        }
        int ans=0;
        for(int i=0;i<=30;i++)
        {
            if(mp[i]>=k)
            {
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};
