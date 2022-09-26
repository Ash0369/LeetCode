class Solution 
{
public:
    TreeNode* find(TreeNode *root,int &x)
    {
        if(root==NULL || root->val==x)
            return root;
        auto l=find(root->left,x);
        auto r=find(root->right,x);
        
        if(l)
            return l;
        return r;
        
    }
    int count(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        return 1+count(root->left)+count(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int &n, int &x) 
    {
        TreeNode *node=find(root,x);
        
        int l=count(node->left);
        int r=count(node->right);
        
        int blue=max(l,r);
        
        int parent=0;
        if(root->val!=x)
            parent=n-(l+r+1);
        
        blue=max(blue,parent);
        
        return blue>(n-blue);
    }
};
