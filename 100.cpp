bool check(TreeNode *p,TreeNode *q)
{
    if(p==NULL && q!=NULL)
    {
        return false;
    }
    if(q==NULL && p!=NULL)
    {
        return false;
    }
    if(q==NULL && p==NULL)
    {
        return true;
    }
    bool left,right;
    if(p->val==q->val)
    {
        right=check(p->right,q->right);
        left=check(p->left,q->left);
    }
    else
    {
        return false;
    }
    return left&right;
}
class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return check(p,q);
    }
};
