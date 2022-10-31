class Solution 
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=m-1;
      
        while(i>=0)
        {
            int k=0;
            int base=matrix[i][0];
            for(int j=i;j<m && k<n;j++)
            {
                int ele=matrix[j][k];
                if(ele!=base)
                    return false;
                k++;
            }
            i--;
        }
     
        int j=1;
        while(j<n)
        {
            int k=0;
            int base=matrix[0][j];
            for(int x=j;x<n && k<m;x++)
            {
                int ele=matrix[k][x];
                if(ele!=base)
                    return false;
                k++;
            }
            j++;
        }
        return true;
    }
};
