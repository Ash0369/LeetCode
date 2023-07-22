class Solution 
{
public:
    int minimumIndex(vector<int>& nums) 
    {
        int ans=-1;
        int tot;
        int n=nums.size();
        vector<int>nm=nums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int x=nums[i];
            while(i<n && nums[i]==x)
            {
                i++;
                cnt++;
            }
            i--;
            if((cnt*2)>n)
            {
                ans=x;
                tot=cnt;
                break;
            }
        }
        if(ans==-1)
        {
            return -1;
        }
        int cnt=0;
        nums=nm;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ans)
            {
                cnt++;
                tot--;
                if((cnt*2)>(i+1) && ((tot)*2)>(n-i-1))
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
