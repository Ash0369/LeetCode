vector<int>d;
void preorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    d.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        d.clear();
        preorder(root);
        TreeNode* temp=root;
        for(int i=1;i<d.size();i++)
        {
            temp->left=NULL;
            struct TreeNode* node=new TreeNode(d[i]);
            temp->right=node;
            temp=temp->right;
        }
        temp=NULL;  
    }
};
