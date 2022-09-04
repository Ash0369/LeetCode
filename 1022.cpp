void make(TreeNode *root,int num,int &sum)
{
    if(root==NULL)
    {
        return;
    }
    if(root->val==0)
    {
        num=num<<1;
    }
    else if(root->val==1)
    {
        num=num<<1;
        num++;
    }
    if(root->left==NULL && root->right==NULL)
    {
        
        sum=sum+num;
        return;
    }
    make(root->left,num,sum);
    make(root->right,num,sum);
}
class Solution 
{
public:
    int sumRootToLeaf(TreeNode* root) 
    {
        int sum=0;
        int num=0;
        make(root,num,sum);
        return sum;
    }
};
