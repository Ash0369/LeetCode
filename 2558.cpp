class Solution 
{
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        #define ll long long
        
        priority_queue<int>pq;
        for(auto x:gifts)
        {
            pq.push(x);
        }
        while(k>0 && !pq.empty())
        {
            int ele=pq.top();
            pq.pop();
            ele=pow(ele,0.5);
            pq.push(ele);
            k--;
        }
        ll int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
