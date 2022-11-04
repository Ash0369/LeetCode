class Solution 
{
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int row=heights.size();
        int col=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int dp[row][col];
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        
        pq.push({0,{0,0}});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            
            int x=node.second.first;
            int y=node.second.second;
            int val=node.first;
            int curr=heights[x][y];
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && nx<row && ny>=0 && ny<col)
                {
                    int new_h=heights[nx][ny];
                    
                    int cost=max(val,abs(curr-new_h));
                    
                    if(dp[nx][ny]>cost)
                    {
                        dp[nx][ny]=cost;
                        
                        pq.push({cost,{nx,ny}});
                    }
                    
                }
            } 
        }
        if(dp[row-1][col-1]==INT_MAX)
            return 0;
        return dp[row-1][col-1];
    }
};
