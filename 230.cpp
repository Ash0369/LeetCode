vector<int>preorder;
void preorder_traversal(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    preorder_traversal(root->left);
    preorder.push_back(root->val);
    preorder_traversal(root->right);
}
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        //preorder traversal is sorted of bst
        preorder.clear();
        preorder_traversal(root);
        return preorder[k-1];
    }
};
