bool safe(vector<string>&board,int row,int column,int n)
{
    for(int i=0;i<n;i++)
    {
        if(board[row][i]=='Q')
            return false;
        if(board[i][column]=='Q')
            return false;
    }
    int i=row;
    int j=column;
    
    while(j<n && i>=0)
    {
        if(board[i][j]=='Q')
            return false;
        i--;
        j++;  
    }
    i=row;
    j=column;
    
    while(j<n && i<n)
    {
        if(board[i][j]=='Q')
            return false;
        i++;
        j++;  
    }
    
    i=row;
    j=column;
    
    while(j>=0 && i>=0)
    {
        if(board[i][j]=='Q')
            return false;
        i--;
        j--;  
    }
    
    i=row;
    j=column;
    
    while(j>=0 && i<n)
    {
        if(board[i][j]=='Q')
            return false;
        i++;
        j--;  
    }
    
    return true;
    
}

void solve(int column,vector<string>&board,vector<vector<string>>&ans,int n)
{
    if(column==n)
       ans.push_back(board);
    for(int i=0;i<n;i++)
    {
        if(safe(board,i,column,n))
        {
            
            board[i][column]='Q';
            solve(column+1,board,ans,n);
            board[i][column]='.';
        }
    }
}
class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};
