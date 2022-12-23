//Method-1 : 

#define ll long long
class Solution 
{
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<int>degree(n,0);
        for(auto x:roads)
        {
            degree[x[0]]++;
            degree[x[1]]++;
        }
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(degree[i]);
        }
        ll int ans=0;
        while(!pq.empty())
        {
            ans+=(1LL*pq.top()*n);
            pq.pop();
            n--;
        }
        return ans;
    }
};

//Method-2 : 


#define ll long long
class Solution 
{
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<int>degree(n,0);
        for(auto x:roads)
        {
            degree[x[0]]++;
            degree[x[1]]++;
        }
        sort(degree.begin(),degree.end(),greater<int>());
        ll int ans=0;
        for(int i=0;i<degree.size();i++)
        {
            ans+=(1LL*degree[i]*n);
            n--;
        }
        return ans;
    }
};
