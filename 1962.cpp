class Solution 
{
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
        }
        for(int i=0;i<k;i++)
        {
            int a=pq.top();
            pq.pop();
            pq.push(a-(a/2));
        }
        int ans=0;
        while(!pq.empty())
        {
            ans=ans+pq.top();
            pq.pop();
        }
        return ans;
    }
};
