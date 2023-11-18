class Solution 
{
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=0;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int len=i-j+1;
            long long int req=sum-(1LL*len*nums[i]);
            while(abs(req)>k)
            {
                sum=sum-nums[j];
                j++;
                len=i-j+1;
                req=sum-(1LL*len*nums[i]);
            }
            ans=max(ans,len);
        }
        return ans;
    }
};
