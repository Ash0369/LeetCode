int camera(TreeNode *root,int &count)
{
    if(root==NULL)
        return 1;
    
    int l=1;
    int r=1;
    
    if(root->left)
    {
        l=camera(root->left,count);
    }
    if(root->right)
    {
        r=camera(root->right,count);
    }
    if(l==0 || r==0)
    {
        count=count+1;
        return 2;
    }
    if(l==2 || r==2)
        return 1;
    
    return 0;        
}
class Solution 
{
public:
    int minCameraCover(TreeNode* root) 
    {
        int count=0;
        int a=camera(root,count);
        if(a==0)
            count=count+1;
        return count;
    }
};
