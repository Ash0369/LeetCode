//Method-1 : 

bool safe(vector<string>&board,int row,int column,int n)
{
    //Other then this 3 direction Queen cannot be placed in remaing because that are later moves.
    for(int i=0;i<column;i++)
    {
        if(board[row][i]=='Q')
            return false;
    }
    int i=row;
    int j=column;
    
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
    int totalNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans.size();
    }
};


//Method-2 : 

void solve(int column,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow, vector<int>&ld,vector<int>&ud,int n)
{
    if(column==n)
    {
        ans.push_back(board);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(leftrow[i]==0 && ld[column+i]==0 && ud[n-1+column-i]==0)
        {
            
            board[i][column]='Q';
            leftrow[i]=1;
            ld[column+i]=1;
            ud[n-1+column-i]=1;
            solve(column+1,board,ans,leftrow,ld,ud,n);
            board[i][column]='.';
            leftrow[i]=0;
            ld[column+i]=0;
            ud[n-1+column-i]=0;
        }
    }
}
class Solution 
{
public:
    int totalNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>ud((2*n)-1,0);
        vector<int>ld((2*n)-1,0);
        solve(0,board,ans,leftrow,ld,ud,n);
        return ans.size();
    }
};
