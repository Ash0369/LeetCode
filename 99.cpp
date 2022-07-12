//Method-1 : O(n) Space Complexity and O(n*log(n)) Time Complexity

vector<int>inorder;
void make_inorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    make_inorder(root->left);
    inorder.push_back(root->val);
    make_inorder(root->right);
}
int i=0;
void make_tree(TreeNode* &root)
{
   if(root==NULL)
   {
        return;
   }
   make_tree(root->left);
   if(inorder[i]==root->val)
   {

   }
   else
   {
        root->val=inorder[i];
   }
   i++;
   make_tree(root->right);
}
class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        inorder.clear();
        make_inorder(root);
        sort(inorder.begin(),inorder.end());
        i=0;
        make_tree(root);

    }
};

//Method-1 : O(1) Space Complexity and O(n) Time Complexity
