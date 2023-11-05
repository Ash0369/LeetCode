class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        int p=0;
        int z;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(grid[i][j]==1)
                {
                    c++;
                }
            }
            if(c==(n-1))
            {
                p++;
                z=i;
            }
        }
        if(p==1)
        {
            return z;
        }
        return -1;
    }
};
