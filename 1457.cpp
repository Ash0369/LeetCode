//Method-1 : Using Bit Manuplation

int count(TreeNode *&root,int n)
{
    if(root==NULL)
        return 0;
    
    
    int a=1<<root->val;//we get bit on at that number
    n=n^a; //Take xor if bit is already on so even count so turned off else turnd on.
    if(root->left==NULL && root->right==NULL)
    {
        if(__builtin_popcount(n)<=1)
            return true;
        
        return false;
    }   
    return count(root->left,n)+count(root->right,n);  
}
class Solution 
{
public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        return count(root,0);
    }
};


//Method-2 : High Time and Space Time Complexity

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
