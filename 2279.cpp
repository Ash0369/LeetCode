//Method-1 : 

class Solution 
{
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int n=capacity.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            pq.push(capacity[i]-rocks[i]);
        }
        while(!pq.empty())
        {
            int demand=pq.top();
            if(demand>additionalRocks)
                break;
            ans++;
            additionalRocks-=demand;
            pq.pop();
        }
        return ans;
    }
};

//Method-2 : 

class Solution 
{
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int n=capacity.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<n;i++)
        {
            int demand=capacity[i];
            if(demand>additionalRocks)
                break;
            ans++;
            additionalRocks-=demand;
        }
        return ans;
    }
};
