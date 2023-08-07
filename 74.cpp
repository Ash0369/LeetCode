class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int rx=0;
        int ry=m-1;
        
        while(rx<=ry)
        {
            int midr=(rx+ry)/2;
            int cx=0;
            int cy=n-1;
            int ans=-1;
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
            if(matrix[midr][0]>target)
            {
                ry=midr-1;
            }
            else
            {
                rx=midr+1;
            }
        }
        return false;
        
    }
};
