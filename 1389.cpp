class Solution 
{
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
        int n=nums.size();
        vector<int>ans(n);
        
        for(int j=0;j<n;j++)
        {
            int pos=index[j];
            for(int i=j+1;i<n;i++)
            {
                if(index[i]<=pos)
                {
                    pos++;
                }
            }
            ans[pos]=nums[j];
        }
        return ans;
    }
};
