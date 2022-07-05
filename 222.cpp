//Method-1

int sum(TreeNode* root)
{
    int c=0;
    if(root==NULL)
    {
        return -1;
    }
    c=1+sum(root->left);
    c=c+1+sum(root->right);
    return c;
}
class Solution
{
public:
    int countNodes(TreeNode* root) 
    {
        return sum(root)+1;
    }
};

//Method-2

int count(TreeNode* root)
{
    int x,y;
    if(root!=NULL)
    {
        x=count(root->left);
        y=count(root->right);
        return x+y+1;
    }
    return 0;
}
class Solution
{
public:
    int countNodes(TreeNode* root) 
    {
        return count(root);
    }
};

//Method-3 

int c=0;
void count_nodes(TreeNode* root)
{
    if(root==NULL)
    {
       return; 
    }
    c=c+1;
    count_nodes(root->left);
    count_nodes(root->right);
}
class Solution
{
public:
    int countNodes(TreeNode* root) 
    {
        c=0;
        count_nodes(root);
        return c;
    }
};
