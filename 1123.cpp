pair<int,TreeNode*>deep(TreeNode *root,int depth,TreeNode *parent)
{
    if(root==NULL)
        return {depth,parent};
    auto l=deep(root->left,depth+1,root);
    auto r=deep(root->right,depth+1,root);
    
    if(l.first>r.first)
        return l;
    if(r.first>l.first)
        return r;
    return {l.first,root};
}
class Solution 
{
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return deep(root,0,root).second;
    }
};
