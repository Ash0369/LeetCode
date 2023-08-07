class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int rx=0;
        int ry=m-1;
        
        for(int i=0;i<m;i++)
        {
            int midr=i;
            int cx=0;
            int cy=n-1;
            while(cx<=cy)
            {
                int midc=(cx+cy)/2;
                if(matrix[midr][midc]==target)
                {
                    return true;
                }
                else if(matrix[midr][midc]>target)
                {
                    cy=midc-1;
                }
                else
                {
                    cx=midc+1;
                }
            }
        }
        return false;
        
    }
};
