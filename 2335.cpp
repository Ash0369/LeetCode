//Method-1 : 

class Solution 
{
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue<int>pq;
        for(auto x:amount)
            pq.push(x);
        int tme=0;
        while(!pq.empty())
        {
            int a=pq.top();
            int b=0;
            pq.pop();
            if(!pq.empty())
            {
                b=pq.top();
                pq.pop();
            }
            if(a==0 && b==0)
                break;
            a--;
            b--;
            if(a>0)
                pq.push(a);
            if(b>0)
                pq.push(b);
            
            
            tme++;
        }
        return tme;
    }
};

//Method-2 : 

class Solution 
{
public:
    int fillCups(vector<int>& amount) 
    {
        sort(amount.begin(),amount.end(),greater<int>());
        int tme=0;
        while(amount[0]>0)
        {
            amount[0]--;
            amount[1]--;
            sort(amount.begin(),amount.end(),greater<int>());
            tme++;
        }
        return tme;
    }
};
