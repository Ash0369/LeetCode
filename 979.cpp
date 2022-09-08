//Mwethod-1 : Passing Cunt as gobal variable

int cnt=0;
int distribute(TreeNode *root)
{
    if(root==NULL)
        return 0;
    
    int l=distribute(root->left);
    root->val=root->val-l; //if demand then decrease otherwise increase
    int r=distribute(root->right);
    root->val=root->val-r;
    cnt=cnt+abs(l)+abs(r);
    
    if(root->val==0)
        return 1; //Asking 1
    if(root->val==1)
        return 0; //No demand
    return -1*(root->val-1);
    
}
class Solution 
{
public:
    int distributeCoins(TreeNode* root) 
    {
        cnt=0;
        distribute(root);
        return cnt;
    }
};


//Passing Count as refernce


int cnt=0;
int distribute(TreeNode *root)
{
    if(root==NULL)
        return 0;
    
    int l=distribute(root->left);
    root->val=root->val-l; //if demand then decrease otherwise increase
    int r=distribute(root->right);
    root->val=root->val-r;
    cnt=cnt+abs(l)+abs(r);
    
    if(root->val==0)
        return 1; //Asking 1
    if(root->val==1)
        return 0; //No demand
    return -1*(root->val-1);
    
}
class Solution 
{
public:
    int distributeCoins(TreeNode* root) 
    {
        cnt=0;
        distribute(root);
        return cnt;
    }
};
