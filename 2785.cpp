
class Solution 
{
public:
    string sortVowels(string s) 
    {
        priority_queue<char,vector<char>,greater<char>>pq;
        for(auto x:s)
        {
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
            {
                pq.push(x);
            }
        }
        string t;
        
        for(auto x:s)
        {
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
            {
               t.push_back(pq.top());
               pq.pop();
            }
            else
            {
                t.push_back(x);
            }
        }
        return t;
    }
};
