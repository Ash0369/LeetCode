vector<int>result;

void preorder(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    result.push_back(root->val);
    preorder(root->left);
    preorder(root->right);

}
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        result.clear();
        preorder(root);
        return result;
    }
};
