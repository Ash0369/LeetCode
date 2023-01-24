class Solution 
{
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size();
        queue<int>q;
        q.push(1);
        int ans=1e9;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        dp[n-1][0]=1;
        int move=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int j=0;j<sz;j++)
            {
                 int cor=q.front();
                 if(cor==(n*n))
                 {
                    return move;
                 }
                 q.pop();
                 for(int i=1;i<=6;i++)
                 {
                     int nx=cor+i;
                     if(nx>(n*n))
                         break;
                     int x=n-1-((nx-1)/(n));
                     int y=(nx-1)%n;
                     if(x%2==n%2)
                     {
                         y=n-1-y;//As order is reverse
                     }
                     if(dp[x][y]==0)
                     {
                         dp[x][y]=1;
                         if(board[x][y]==-1)
                         {
                             q.push(nx);
                         }
                         else
                         {
                             q.push(board[x][y]);
                         }
                     } 
                 }
            }
            move++;
           
        }
        return -1;
    }
};
