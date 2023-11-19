class Solution 
{
public:
    int reductionOperations(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        
        reverse(nums.begin(),nums.end());
        int load=0;
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            int cnt=0;
            while(i<n && nums[i]==curr)
            {
                cnt++;
                i++;
            }
            if(i!=n)
            {
                i--;
                ans+=cnt+load;
                load+=cnt;
            }
        }
        return ans;
    }
};
