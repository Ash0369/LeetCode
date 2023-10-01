class Solution 
{
public:
    int minSizeSubarray(vector<int>& nums, int target) 
    {
        #define ll long long
        ll int tot=0;
        int n=nums.size();
        for(auto x:nums)
        {
            tot+=x;
        }
        int extra=target/tot;
        int sz=(extra)*n;
        tot=1LL*extra*tot;
        ll int need=target-tot;
        
        int left=0;
        int su=0;
        extra=1e9;
        for(int i=0;i<n;i++)
        {
            su+=nums[i];
            while(su>need)
            {
                su-=nums[left];
                left++;
            }
            if(su==need)
            {
                extra=min(extra,i-left+1);
            }
        }
        for(int i=0;i<n;i++)
        {
            su+=nums[i];
            bool r=true;
            if(left==n)
            {
                r=false;
                break;
            }
            while(su>need)
            {
                su-=nums[left];
                left++;
                if(left==n)
                {
                    r=false;
                    break;
                }
            }
            if(su==need)
            {
                extra=min(extra,n-left+i+1);
            }
            if(r==false)
            {
                break;
            }
        }
        if(extra==1e9)
        {
            return -1;
        }
        return sz+extra;
    }
};
