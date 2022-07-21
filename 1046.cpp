class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int n=stones.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        while(!pq.empty())
        {
            if(pq.size()>=2)
            {
                int a,b;
                a=pq.top();
                pq.pop();
                b=pq.top();
                cout<<a<<" "<<b<<endl;
                pq.pop();
                if(a!=b)
                {
                    pq.push(a-b);
                }
            }
            else
            {
                if(pq.size()==0)
                {
                    return 0;
                }
                else
                {
                    return pq.top();
                    pq.pop();
                }
                break;
            }
        }
        return 0;
    }
};
