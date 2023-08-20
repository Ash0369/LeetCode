class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(),nums.end()))
        {
            return 0;
        }
        int ans=1e9;
        int n=nums.size();
        for(int j=0;j<=n;j++)
        {
            for(int m=j;m<=n+1;m++)
            {
                int curr=0;
                for(int k=0;k<n;k++)
                {
                    if(k<j && nums[k]!=1)
                    {
                        curr++;
                    }
                    else if(k>=j && k<m && nums[k]!=2)
                    {
                        curr++;
                    }
                    else if(k>=m && nums[k]!=3)
                    {
                        curr++;
                    }
                }
                ans=min(ans,curr);
            }
        }
        int curr=0;
        for(int k=0;k<n;k++)
        {
            if(nums[k]!=1)
            {
                curr++;
            }

        }
        ans=min(ans,curr);
        curr=0;
        for(int k=0;k<n;k++)
        {
            if(nums[k]!=2)
            {
                curr++;
            }

        }
        ans=min(ans,curr);
        curr=0;
        for(int k=0;k<n;k++)
        {
            if(nums[k]!=3)
            {
                curr++;
            }

        }
        ans=min(ans,curr);
        return ans;
    }
};
