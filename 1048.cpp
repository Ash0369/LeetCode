bool check(string &s1 ,string &s2)
{
    if(s1.size()!=s2.size()+1)
        return false;
    
    int f=0;
    int s=0;
    int count=0;
    while(f<s1.size())
    {
        if(s1[f]!=s2[s])
        {
            f++;
        }
        else
        {
            f++;
            s++;
        }
    }
    
    return (f==s1.size() && s==s2.size());
}

bool comp(string &s1 , string &s2)
{
    return s1.size()<s2.size();
}
class Solution 
{
public:
    int longestStrChain(vector<string>&nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);//Sort according to length
        vector<int>dp(n+1,1); 
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
               // if(nums[prev]<nums[i])
                if(check(nums[i],nums[prev]))
                {
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;    
    }
};
