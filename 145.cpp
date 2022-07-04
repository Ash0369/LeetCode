vector<int>result;
void postorder(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    result.push_back(root->val);

}
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        result.clear();
        postorder(root);
        return result;
    }
};
