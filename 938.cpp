//Method-1:

int sum=0;
void check(TreeNode *root,int low,int high)
{
    if(!root)
        return;
    int n=root->val;
    if(n>=low && n<=high)
        sum+=n;
    check(root->left,low,high);
    check(root->right,low,high);
}
class Solution 
{
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        sum=0;
        check(root,low,high);
        return sum;
    }
};


//Method-2:


int sum=0;
void check(TreeNode *root,int &low,int &high)
{
    if(!root)
        return;
    int n=root->val;
    if(n>=low && n<=high)
    {
        sum+=n;
        check(root->left,low,high);
        check(root->right,low,high);
    }
        
    else if(n>high)
        check(root->left,low,high);
    else if(n<low)
        check(root->right,low,high);
}
class Solution 
{
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        sum=0;
        check(root,low,high);
        return sum;
    }
};
