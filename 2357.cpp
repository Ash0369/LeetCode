class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums)
            pq.push(x);
        int op=0;
        int sub=0;
        while(!pq.empty())
        {
            int ele=pq.top();
            pq.pop();
            ele=ele-sub;
            if(ele==0)
                continue;
            
            sub=sub+ele;
            op++;
        }
        return op;
    }
};
