bool dfs(TreeNode *root,TreeNode *subroot)
{
    if(root==NULL && subroot==NULL)
        return true;
    if(root==NULL || subroot==NULL)
        return false;
    if(root->val!=subroot->val)
        return false;
    return dfs(root->left,subroot->left) && dfs(root->right,subroot->right);
}
bool check(TreeNode *root,TreeNode *&subroot)
{
    if(root==NULL)
        return false;
    if(root->val==subroot->val)
    {
        bool res=dfs(root,subroot);
        if(res)
            return true;
    }
    return check(root->left,subroot)|check(root->right,subroot);
}
class Solution 
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        return check(root,subRoot);
    }
};
