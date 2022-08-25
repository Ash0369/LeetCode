int h=0;
int val=0;
void deep(TreeNode* root,int height)
{
    if(root->left==NULL && root->right==NULL && height>=h)
    {
        
        if(height==h)
        {
            val=val+root->val;
        }
        else
        {
            val=root->val;
        }
        h=height;
    }
    if(root->left)
    {
        deep(root->left,height+1);
    }
    if(root->right)
    {
        deep(root->right,height+1);
    }
}
class Solution 
{
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        h=0;
        val=0;
        deep(root,0);
        return val;
    }
};
