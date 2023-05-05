const int mod=1e9+7;
class Solution 
{
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums)
        {
            pq.push(x);
        }
        while(k--)
        {
            int a=pq.top();
            pq.pop();
            pq.push(a+1);
        }
        int ans=1;
        while(!pq.empty())
        {
            ans=(1LL*ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};
