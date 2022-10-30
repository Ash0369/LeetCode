TreeNode *inorder(TreeNode *root,TreeNode *parent)
{
    if(root==NULL)
        return parent;
    TreeNode *ans=inorder(root->left,root);
    root->left=NULL;
    root->right=inorder(root->right,parent);
    return ans;
}
class Solution 
{
public:
    TreeNode* increasingBST(TreeNode* root) 
    {
        return inorder(root,NULL);
    }
};
