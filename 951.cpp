//Method-1 : 

bool check(TreeNode *&root1,TreeNode *&root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->val==root2->val)
    {
        if(check(root1->left,root2->left) && check(root1->right,root2->right))
            return true;
        swap(root1->left,root1->right);
        if(check(root1->left,root2->left) && check(root1->right,root2->right))
            return true;
    }
    return false;
}
class Solution 
{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        return check(root1,root2);
    }
};


//Method-2 : Without using Swap


bool check(TreeNode *&root1,TreeNode *&root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->val==root2->val)
    {
        if(check(root1->left,root2->left) && check(root1->right,root2->right))
            return true;
        if(check(root1->left,root2->right) && check(root1->right,root2->left))
            return true;
    }
    return false;
}
class Solution 
{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        return check(root1,root2);
    }
};
