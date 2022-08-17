//Method-1 : 

int res=INT_MIN;
int sum(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l_sum=sum(root->left);
    int r_sum=sum(root->right);

    res=max(res,l_sum+r_sum+root->val);
    res=max(res,l_sum+root->val);
    res=max(res,r_sum+root->val);
    res=max(res,root->val);

    return max(max(l_sum,r_sum)+root->val,root->val);
}
class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        res=INT_MIN;
        sum(root);
        return res;
    }
};

//Method-2 : 

int res=INT_MIN;
int sum(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l_sum=max(0,sum(root->left));
    int r_sum=max(0,sum(root->right));

    res=max(res,l_sum+r_sum+root->val);

    return max(l_sum,r_sum)+root->val;
}
class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        res=INT_MIN;
        sum(root);
        return res;
    }
};
