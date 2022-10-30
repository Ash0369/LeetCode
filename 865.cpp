int mx_depth=0;
TreeNode *lca;
int deep(TreeNode *root,int depth)
{
    int l=depth;
    int r=depth;
    if(root->left)
        l=deep(root->left,depth+1);
    if(root->right)
        r=deep(root->right,depth+1);
    
    mx_depth=max(mx_depth,depth);
    
    if(l==mx_depth && r==mx_depth)
        lca=root;
    return max(l,r);
}
class Solution 
{
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        mx_depth=0;
        deep(root,0);
        return lca;
    }
};
