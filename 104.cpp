int max_depth(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=max_depth(root->left);
    int b=max_depth(root->right);

    return 1+max(a,b);
}
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        return max_depth(root);
    }
};
