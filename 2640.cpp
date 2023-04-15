#define ll long long
class Solution 
{
public:
    vector<long long> findPrefixScore(vector<int>& nums) 
    {
        vector<ll int>ans;
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            ll int score=nums[i]+mx;
            if(i==0)
            {
                ans.push_back(score);
            }
            else
            {
                score=score+ans[i-1];
                ans.push_back(score);
            }
        }
        return ans;
    }
};
