class Solution 
{
public:
    int countBeautifulPairs(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int d1=(to_string(nums[i])[0])-'0';
            for(int j=i+1;j<n;j++)
            {
                int d2=nums[j]%10;
                if(__gcd(d1,d2)==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
