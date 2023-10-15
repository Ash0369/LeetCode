class Solution 
{
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(j-i)>=id && abs(nums[i]-nums[j])>=vd)
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
