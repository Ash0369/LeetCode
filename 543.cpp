int depth=0;
int max_depth(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=max_depth(root->left);
    int b=max_depth(root->right);

    depth=max(depth,a+b);

    return 1+max(a,b);
}
class Solution 
{
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        depth=0;
        max_depth(root);
        return depth;
    }
};
