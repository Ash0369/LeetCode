//Method-1 : Using pair

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


//Method-2 : Using less space


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
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        mx_depth=0;
        deep(root,0);
        return lca;
    }
};
