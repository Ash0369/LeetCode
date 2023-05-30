//Method-1 :

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)//taking all rows 1 by 1
        {
            int left=0;
            int right=n-1;
            
            while(right>left)
            {
                swap(matrix[i][left],matrix[i][right]);
                right--;
                left++;
            }
        }
        
    }
};

//Method-2 :

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=j)
                {
                    continue;
                }
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
