int height(TreeNode *root)
{
    if(root==NULL)
        return 0;
    
    return 1+max(height(root->left),height(root->right));
}
void place(TreeNode *root,vector<vector<string>>&vec,int r,int c,int &h)
{
    if(root==NULL)
        return;
    if(root->left)
    {
        vec[r+1][c-int(pow(2,h-r-1))]=to_string(root->left->val);
        place(root->left,vec,r+1,c-int(pow(2,h-r-1)),h);
    }
    if(root->right)
    {
        vec[r+1][c+int(pow(2,h-r-1))]=to_string(root->right->val);
        place(root->right,vec,r+1,c+int(pow(2,h-r-1)),h);
    }  
}
class Solution 
{
public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        
        int h=height(root);
        h--;
        int n=pow(2,h+1)-1;
        vector<vector<string>>ans(h+1,vector<string>(n,""));
        
        n=(n-1)/2;
        ans[0][n]=to_string(root->val);
        
        place(root,ans,0,n,h);
        return ans;
    }
};
