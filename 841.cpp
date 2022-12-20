class Solution 
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        queue<int>q;
        q.push(0);
        int n=rooms.size();
        vector<bool>dp(n,false);
        dp[0]=true;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto x:rooms[ele])
            {
                if(dp[x]==false)
                {
                    dp[x]=true;
                    q.push(x);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==false)
                return false;
        }
        return true;
    }
};
