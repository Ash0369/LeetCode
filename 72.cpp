//Method-1 : Memoization

int distance(string &word1,string &word2,int i,int j,vector<vector<int>>&vec)
{
    //(i,j) signify no of operation to match word1 upto i index with word2 upto j index
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    
    if(word1[i]==word2[j])
        return distance(word1,word2,i-1,j-1,vec);
    if(vec[i][j]==-1)
    {
        int delete_op=1+distance(word1,word2,i-1,j,vec);
        int insert_op=1+distance(word1,word2,i,j-1,vec);
        int replace_op=1+distance(word1,word2,i-1,j-1,vec);
        
        vec[i][j]=min(delete_op,min(insert_op,replace_op));
    }
    return vec[i][j];  
}
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>vec(m,vector<int>(n,-1));
        return distance(word1,word2,m-1,n-1,vec);
    }
};


//Method-2 : Tabulation

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=j; //1st base case where string 1 is exhausted
        }
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i; //2nd base case where string 2 is exhausted
        }
         
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //Copy the recurance 
                
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    int delete_op=1+dp[i-1][j];
                    int insert_op=1+dp[i][j-1];
                    int replace_op=1+dp[i-1][j-1];
                    dp[i][j]=min(delete_op,min(insert_op,replace_op));
                }
                
            }
        }
        return dp[m][n];
    }
};
