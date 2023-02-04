class Solution 
{
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        unordered_set<int>ban;
        for(auto x:banned)
        {
            if(x<=n)
                ban.insert(x);
        }
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(ban.find(i)==ban.end() && (sum+i)<=maxSum)
            {
                sum+=i;
                ans++;
            }
        }
        return ans;
    }
};
