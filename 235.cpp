TreeNode* anestor(TreeNode* root,TreeNode* p,TreeNode*q)
{
    if(root==NULL)
    {
        return NULL;
    }
    int data=root->val;
    if((p->val>=data && q->val<=data) || (p->val<=data && q->val>=data))
    {
        return root;
    }
    else if(p->val>=data && q->val>=data)
    {
        return anestor(root->right,p,q);
    }
    else 
    {
       return anestor(root->left,p,q);
    }
}
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return anestor(root,p,q);
    }
};
