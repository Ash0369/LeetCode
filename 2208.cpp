class Solution 
{
public:
    int halveArray(vector<int>& nums) 
    {
        int op=0;
        double sum=0;
        priority_queue<double>pq;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            pq.push(nums[i]);
        }
        double curr=sum;
        while(curr>(sum/2))
        {
            double a=pq.top();
            pq.pop();
            pq.push(a/2);
            curr=curr-a+(a/2);
            op++;
        }
        return op;
    }
};
