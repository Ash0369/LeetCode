bool result=true;
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int node_left=height(root->left);
    int node_right=height(root->right);
    if(abs(node_left-node_right)>1)
    {
        result=false;
    }
    return 1+max(node_left,node_right);
}
class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        result=true;
        height(root);
        return result;
    }
};
