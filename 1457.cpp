bool check_parity(vector<int>&num)
{
    int count=0;
    for(int i=1;i<=9;i++)
    {
        if(num[i]%2==1)
            count++;
    }
    if(count>1)
        return false;
    
    return true;
}
int count(TreeNode *root,vector<int>num)
{
    if(root==NULL)
        return 0;
    
    num[root->val]=num[root->val]+1;
    if(root->left==NULL && root->right==NULL)
    {
        bool ans=check_parity(num);
        if(ans)
            return 1;
        return 0;
    }
    
    return count(root->left,num)+count(root->right,num);  
}
class Solution 
{
public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int>num(10,0);
        return count(root,num);
    }
};
