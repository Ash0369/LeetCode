class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        long long int prev=-1*(1e15);
        for(auto x:nums)
        {
            if(x==prev)
                return true;
            prev=x;
        }
        return false;
    }
};
