bool isvalid(vector<vector<char>>& board,int x,int y,char num)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][y]==num)
            return false;
        
         if(board[x][i]==num)
            return false;
    }
    
    int startx=x/3;
    int starty=y/3;
    
    for(int i=(startx*3);i<(startx*3)+3;i++)
    {
        for(int j=(starty*3);j<(starty*3)+3;j++)
        {
            if(board[i][j]==num)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(isvalid(board,i,j,c))
                    {
                         board[i][j]=c;
                         
                         if(solve(board)==true)
                             return true;
                         
                         board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};
