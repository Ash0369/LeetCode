class Solution 
{
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int>ans;
        reverse(nums.begin(),nums.end());
        for(auto x:nums)
        {
            while(x>0)
            {
                ans.push_back(x%10);
                x=x/10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
