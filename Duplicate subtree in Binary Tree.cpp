vector<vector<int>>data;
int dfs(Node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    if(root->left==NULL)
    {
        vector<int>t;
        int v=dfs(root->right);
        if(v!=-1)
        {
            data.push_back({-1,root->data,v});
        }
        return -1;
    }
    if(root->right==NULL)
    {
        vector<int>t;
        int v=dfs(root->left);
        if(v!=-1)
        {
            data.push_back({v,root->data,-1});
        }
        return -1;
    }
    int v1=dfs(root->left);
    int v2=dfs(root->right);
    
    if(v1!=-1 && v2!=-1)
    {
        data.push_back({v1,root->data,v2});
    }
    return -1;
    
}
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) 
    {
         data.clear();
         dfs(root);
         for(int i=0;i<data.size();i++)
         {
             for(int j=i+1;j<data.size();j++)
             {
                 
                 if(data[i]==data[j])
                 {
                     return 1;
                 }
             }
         }
         return 0;
    }
};
