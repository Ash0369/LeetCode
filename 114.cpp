//Method-1

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

//Method-2 O(1) Space complexity

void flat(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    flat(root->left);
    flat(root->right);
    if(root->left)
    {
        TreeNode* temp=root->left;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=root->right;
        root->right=root->left;
    }
    root->left=NULL;
    
}
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        flat(root); 
    }
};
