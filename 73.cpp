//Method-1 : 

void make_row_zero(vector<vector<int>>&matrix ,int r)
{  
    int n=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        matrix[r][i]=0;
    }
}

void make_column_zero(vector<vector<int>>&matrix ,int c)
{  
    int m=matrix.size();
    for(int i=0;i<m;i++)
    {
        matrix[i][c]=0;
    }
}

class Solution 
{
public:
    void setZeroes(vector<vector<int>>&matrix)
    {
        vector<int>row;
        vector<int>column;
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        for (auto x:row)
        {
            
            make_row_zero(matrix,x);
        }
        for (auto x:column)
        {
            make_column_zero(matrix,x);
        }
    }
};


//Method-2 : 

class Solution 
{
public:
    void setZeroes(vector<vector<int>>&matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        bool row_flag=false;
        bool column_flag=false;
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0)
                    {
                        row_flag=true;
                    }
                    if(j==0)
                    {
                        column_flag=true;
                    }
                    
                    if(i!=0 && j!=0)
                    {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(row_flag)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
        
        if(column_flag)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
       
    }
};
