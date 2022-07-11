//Method-1:Time Complexity O(1) and Space Complexity O(n)

int i=-1;
vector<int>inorder;
void inorder_traversal(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    inorder.push_back(root->val);
    inorder_traversal(root->right);
}
class BSTIterator 
{
public:
    BSTIterator(TreeNode* root) 
    {
        i=-1;
        inorder.clear();
        inorder_traversal(root);
    }
    
    int next() 
    {
        i++;
        return inorder[i];
    }
    
    bool hasNext() 
    {
        if((i+1)<inorder.size())
        {
            return true;
        }
        return false;
    }
};

//Method-2: Time Complexity O(1) and Space Complexity O(1)

