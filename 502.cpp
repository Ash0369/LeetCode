class Solution 
{
public:
    int findMaximizedCapital(int k,int w,vector<int>&profits,vector<int>&capital) 
    {
        int n=profits.size();
        vector<vector<int>>vec;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(i<n && vec[i][0]<=w)
        {
            pq.push(vec[i][1]);
            i++;
        }
        while(k>0 && !pq.empty())
        {
            w=w+pq.top();
            pq.pop();
            while(i<n && vec[i][0]<=w)
            {
                pq.push(vec[i][1]);
                i++;
            }
            k--;
        }
        return w;
    }
};
