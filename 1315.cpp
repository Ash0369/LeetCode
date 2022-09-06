int val(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->val;
}
int sum(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int s=0;
    if(root->val%2==0)
    {
        if(root->right)
        {
            s=s+val(root->right->left)+val(root->right->right);
        }
        if(root->left)
        {
            s=s+val(root->left->left)+val(root->left->right);
        }
    }
    return sum(root->left)+sum(root->right)+s;
}

class Solution 
{
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
        return sum(root);
    }
};
