class KthLargest 
{
public:
    int index;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) 
    {
        index=k;
        for(auto x:nums)
        {
            pq.push(x);
        }
        while(pq.size()>k)
            pq.pop();
        
    }
    
    int add(int val) 
    {
        pq.push(val);
        while(pq.size()>index)
            pq.pop();
        return pq.top();
    }
};
