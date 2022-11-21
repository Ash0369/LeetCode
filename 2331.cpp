bool dfs(TreeNode *root)
{
    if(root->left==NULL && root->right==NULL)
        return root->val;
    int a=dfs(root->left);
    int b=dfs(root->right);
    
    if(root->val==3)
        return a&b;
    
    return a|b;
}
class Solution 
{
public:
    bool evaluateTree(TreeNode* root)
    {
        return dfs(root);
    }
};
