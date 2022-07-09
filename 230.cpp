//Method-1 : O(n) Space Complexity

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

//Method-2 : O(1) Space Complexity.

int counter=0;
int result;
void preorder_traversal(TreeNode* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    
    preorder_traversal(root->left,k);
    counter++;
    if(counter==k)
    {
        result=root->val;
    }
    preorder_traversal(root->right,k);
}
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        //preorder traversal is sorted of bst
        counter=0;
        result=0;
        preorder_traversal(root,k);
        return result;
    }
};
