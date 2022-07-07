bool serach_tree(TreeNode* root,TreeNode* x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->val==x->val)
    {
        return true;
    }
    bool a=serach_tree(root->left,x);
    bool b=serach_tree(root->right,x);

    if(a||b)
    {
        return true;
    }
    return false;
}



TreeNode* find_ancestor(TreeNode* root,TreeNode*p,TreeNode* q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==p->val)
    {
        return p;
    }
    if(root->val==q->val)
    {
        return q;
    }
    bool a=serach_tree(root->left,p);
    bool b=serach_tree(root->left,q);

    bool c=serach_tree(root->right,p);
    bool d=serach_tree(root->right,q);

    if((a&&d) || (c&&b))
    {
        return root;
    }
    else if((a&&b))
    {
        return find_ancestor(root->left,p,q);
    }
   
    return find_ancestor(root->right,p,q);
    
    
}

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return find_ancestor(root,p,q);
    }
};
