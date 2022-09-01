void invert(TreeNode* &root)
{
    if(root==NULL)
    {
        return;
    }
    swap(root->left,root->right);
    invert(root->left);
    invert(root->right);
}
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return root;
    }
};
