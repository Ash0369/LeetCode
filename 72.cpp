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
