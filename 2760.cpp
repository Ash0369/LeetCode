class Solution 
{
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) 
    {
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            int ele=nums[i];
            if(ele%2==0 && ele<=threshold)
            {
                int p=0;
                int t=0;
                int j=i;
                for(j=i;j<n;j++)
                {
                    if(nums[j]%2==p && nums[j]<=threshold)
                    {
                        t++;
                    }
                    else
                    {
                        i=j-1;
                        break;
                    }
                    p=!p;
                }
                ans=max(ans,t);
                if(j==n)
                {
                    break;
                }
                i++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
