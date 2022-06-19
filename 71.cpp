class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>sol;
        int s=nums.size();
        int count=1<<s;
        for(int i=0;i<count;i++)
        {
            vector<int>sub;
            for(int j=0;j<s;j++)
            {
                int temp=1<<j;
                int res=temp&i;
                if(res!=0)
                {
                    sub.push_back(nums[j]);
                }
            }
            sol.push_back(sub);
        }
        return sol;
    }
};
