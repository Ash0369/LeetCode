class Solution 
{
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        int n=status.size();
        map<int,bool>box;
        map<int,bool>key;
        int tofee=0;
        vector<bool>dp(n,false);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(status[i]==1)
                key[i]=true;
        }
        for(auto x:initialBoxes)
        {
            box[x]=true;
            if(key[x]==true && dp[x]==false)
            {
                q.push(x);
                dp[x]=true;
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            tofee+=candies[node];
            for(auto x:containedBoxes[node])
            {
                box[x]=true;
                if(key[x]==true && dp[x]==false)
                {
                    dp[x]=true;
                    q.push(x);
                }
            }
            for(auto x:keys[node])
            {
                key[x]=true;
                if(box[x]==true && dp[x]==false)
                {
                    dp[x]=true;
                    q.push(x);
                }
            }
            
        }
        return tofee;
    }
};
