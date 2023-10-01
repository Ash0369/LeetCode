class Solution 
{
public:
    int maxSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        int add=nums[0];
        for(auto x:nums)
        {
            add=add&x;
        }
        if(add!=0)
        {
            return 1;
        }
        int ans=0;
        int curr=nums[0];
        for(int i=0;i<n;i++)
        {
            curr=curr&nums[i];
            cout<<curr<<endl;
            if(curr==add)
            {
                ans++;
                if(i!=n-1)
                {
                    curr=nums[i+1];
                }
            }
        }
        return ans;
    }
};
