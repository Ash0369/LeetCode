//Method-1 : 

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        vector<vector<int>>dp(m,vector<int>(n,0));
        int i=0;
        int j=n-1;
        int k=m-1;
        int l=0;
        
        while(i<m && l<n)
        {
            //ith row
            
            for(int a=0;a<n;a++)
            {
                if(dp[i][a]==0)
                {
                    ans.push_back(matrix[i][a]);
                    dp[i][a]=1;
                }
            }
            
            //jth column
            
            for(int a=0;a<m;a++)
            {
                if(dp[a][j]==0)
                {
                    ans.push_back(matrix[a][j]);
                    dp[a][j]=1;
                }
            }
            
             //kth row
            
            for(int a=n-1;a>=0;a--)
            {
                if(dp[k][a]==0)
                {
                    ans.push_back(matrix[k][a]);
                    dp[k][a]=1;
                }
            }
            
             //lth col
            
            for(int a=m-1;a>=0;a--)
            {
                if(dp[a][l]==0)
                {
                    ans.push_back(matrix[a][l]);
                    dp[a][l]=1;
                }
            }
            
            i++;
            j--;
            k--;
            l++;
        }
        return ans;
    }
};

//Method-2 : 

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=m-1;
        while(left<=right && top<=bottom)
        {
            for(int j=left;j<=right;j++)
            {
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int j=top;j<=bottom;j++)
            {
                ans.push_back(matrix[j][right]);
            }
            right--;
            for(int j=right;j>=left;j--)
            {
                if(top>bottom)
                {
                    continue;
                }
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
            for(int j=bottom;j>=top;j--)
            {
                if(left>right)
                {
                    continue;
                }
                ans.push_back(matrix[j][left]);
            }
            left++;
        }
        return ans;
    }
};
