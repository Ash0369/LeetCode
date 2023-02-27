bool same(int row_start,int col_start,int row_end,int col_end,vector<vector<int>>& grid)
{
    int val=grid[row_start][col_start];
    for(int i=row_start;i<row_end;i++)
    {
        for(int j=col_start;j<col_end;j++)
        {
            if(grid[i][j]!=val)
            {
                return false;
            }
        }
    }
    return true;
}
Node *make(vector<vector<int>>& grid,int row_start,int col_start,int row_end,int col_end)
{
    Node *node=new Node();
    if(same(row_start,col_start,row_end,col_end,grid))
    {
        node->isLeaf=true;
        node->val=grid[row_start][col_start];
        node->topLeft=NULL;
        node->topRight=NULL;
        node->bottomLeft=NULL;
        node->bottomRight=NULL;
    }
    else
    {
        int rmid=(row_start+row_end)/2;
        int cmid=(col_start+col_end)/2;
        node->topLeft=make(grid,row_start,col_start,rmid,cmid);
        node->bottomLeft=make(grid,rmid,col_start,row_end,cmid);
        node->topRight=make(grid,row_start,cmid,rmid,col_end);   
        node->bottomRight=make(grid,rmid,cmid,row_end,col_end);
        node->isLeaf=false;
        node->val=0;
    }
    return node;
}
class Solution 
{
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        return make(grid,0,0,n,n);
    }
};
