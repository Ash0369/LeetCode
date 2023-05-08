class Solution 
{
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            set<int>st;
            set<int>s;
            for(int j=0;j<n;j++)
            {
                s.insert(matrix[j][i]);
                st.insert(matrix[i][j]);
            }
            if(st.size()!=n || s.size()!=n)
            {
                return false;
            }
        }
        
        return true;
    }
};
