class Solution 
{
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<s2.size();i++)
        {
            pq.push(s2[i]-'a');
        }
        bool wrong=false;
        sort(s1.begin(),s1.end());
        int cnt=0;
        for(int i=0;i<s1.size();i++)
        {
            int need=s1[i]-'a';
            if(pq.top()<=need)
            {
                cnt++;
            }
            if(pq.top()<need)
            {
                wrong=true;
            }
            pq.pop();
        }
        if(wrong==false)
        {
            return true;
        }
        return cnt==s1.size();
    }
};
