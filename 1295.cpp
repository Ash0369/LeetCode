class Solution 
{
public:
    int findNumbers(vector<int>& nums) 
    {
        int ans=0;
        for(auto x:nums)
        {
            int a=log10(x);
            if(a%2!=0)
                ans++;
        }
        return ans;
    }
};
