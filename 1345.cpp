class Solution 
{
public:
    int minJumps(vector<int>& arr) 
    {
        int n=arr.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int>dp(n+1,0);
        queue<int>q;
        dp[0]=0;
        q.push(0);
        int steps=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int node=q.front();
                if(node==n-1)
                {
                    return steps;
                }
                q.pop();
                //We can go at node+1
                if(node+1<n && dp[node+1]==0)
                {
                    q.push(node+1);
                    dp[node+1]=1;
                }
                //We can go at node-1
                if(node-1>=0 && dp[node-1]==0)
                {
                    q.push(node-1);
                    dp[node-1]=1;
                }
                //We can go at same value index
                for(auto index:mp[arr[node]])
                {
                    if(dp[index]==0)
                    {
                        q.push(index);
                        dp[index]=1;
                    }
                }
                mp.erase(arr[node]);//As all nodes visited but it will create TLE in future by just going in the loop
            }
            steps++;
            
        }
        return -1;
        
    }
};
