int largestRectangleArea(vector<int>& heights) 
{
    int n=heights.size();
    int max_area=0;
    stack<int>st;
    for(int i=0;i<=n;i++)
    {
        while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
        {
            int r=i;
            int h=heights[st.top()];
            st.pop();
            int l=-1;
            if(!st.empty())
                l=st.top();
            int area=(r-l-1)*h;
            max_area=max(max_area,area);
        }
        st.push(i);
    }
    return max_area;
}

class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>vec(m,0);
        int area=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    vec[j]=vec[j]+1;
                else
                    vec[j]=0;
            }
            area=largestRectangleArea(vec);
            res=max(area,res);
        }
        return res;
    }
};
