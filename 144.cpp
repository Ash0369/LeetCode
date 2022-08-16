//Method-1 : Recursive

vector<int>result;

void preorder(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    result.push_back(root->val);
    preorder(root->left);
    preorder(root->right);

}
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        result.clear();
        preorder(root);
        return result;
    }
};

//Method-2 : Iterative 

class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*>st;
        st.push(root);
        vector<int>result;
        if(root==NULL)
        {
            return result;
        }
        while(!st.empty())
        {
            result.push_back(st.top()->val);
            TreeNode* temp=st.top();
            st.pop();
            if(temp->right!=NULL)
            {
                st.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                st.push(temp->left);
            }
        }
        return result;
    }
};
