class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
        }
        int size=0;
        int removed=0;
        while(!pq.empty())
        {
            size++;
            removed=removed+pq.top().first;
            if(removed>=(n/2))
            {
                return size;
            }
            pq.pop();

        }
        return 0;
    }
};
