//Method-1 : DOUBLE TRAVERSAL

pair<int,int> dfs(TreeNode *root,int &val,int depth,TreeNode *parent)
{
    if(root==NULL)
        return {-1,-1};
    if(root->val==val)
    {
        return {depth,parent->val};
    }
    auto l=dfs(root->left,val,depth+1,root);
    if(l.first!=-1)
        return l;
    return dfs(root->right,val,depth+1,root);
}
class Solution 
{
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {

        auto d1=dfs(root,x,0,root);
        auto d2=dfs(root,y,0,root);
        
        return d1.first==d2.first && d1.second!=d2.second;
    }
};


//Method-2 : SINGLE TRAVERSAL


int x_depth=0;
int y_depth=0;
int x_parent=0;
int y_parent=0;
void dfs(TreeNode *root,int &x,int &y,int parent,int depth)
{
    if(root==NULL)
        return;
    if(root->val==x)
    {
        x_depth=depth;
        x_parent=parent;
    }
    if(root->val==y)
    {
        y_depth=depth;
        y_parent=parent;
    }
    dfs(root->left,x,y,root->val,depth+1);
    dfs(root->right,x,y,root->val,depth+1);
}
class Solution 
{
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        x_depth=0;
        y_depth=0;
        x_parent=0;
        y_parent=0;
        dfs(root,x,y,0,0);
        
        return x_depth==y_depth && x_parent!=y_parent;
        
    }
};
