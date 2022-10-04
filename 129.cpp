//Method-1 : 

int sum(TreeNode *root,int value)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
    {
        return (10*value)+root->val;
    }
    int a=root->val;
    value=(10*value)+a;
    return sum(root->left,value)+sum(root->right,value);
}
class Solution 
{
public:
    int sumNumbers(TreeNode* root) 
    {
        return sum(root,0);
    }
};


//Method-2 : 


int sum(TreeNode *root,int value)
{
    if(root==NULL)
        return 0;
    value=(10*value)+root->val;
    if(root->left==root->right)
    {
        return value;
    }
    return sum(root->left,value)+sum(root->right,value);
}
class Solution 
{
public:
    int sumNumbers(TreeNode* root) 
    {
        return sum(root,0);
    }
};
