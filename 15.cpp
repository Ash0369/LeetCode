class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int k=n-1;
            int j=i+1;
            while(j<k)
            {
                if((nums[i]+nums[j]+nums[k])==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k--;
                    while(k>=0 && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                    j++;
                    while(j<n && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                }
                else if((nums[i]+nums[j]+nums[k])>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};
