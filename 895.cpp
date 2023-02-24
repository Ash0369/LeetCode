class FreqStack 
{
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    map<int,int>mp;
    int pos;
    FreqStack() 
    {
        pos=0;
    }
    
    void push(int val) 
    {
        mp[val]++;
        pq.push({mp[val],{pos,val}});
        pos++;
    }
    
    int pop() 
    {
        int ele=pq.top().second.second;
        mp[ele]--;
        pq.pop();
        return ele;
    }
};
