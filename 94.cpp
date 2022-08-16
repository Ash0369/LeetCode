//Method-1 : Recurssive way

vector<int>result;
void inorder_Traversal(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_Traversal(root->left);
    result.push_back(root->val);
    inorder_Traversal(root->right);
}
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    { 
        result.clear();
        inorder_Traversal(root);
        return result;
    }
};

//Method-2 : Iterative way

class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        stack<TreeNode*>st;
        while(root!=NULL || !st.empty())
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            if(root==NULL)
            {
                result.push_back(st.top()->val);
                root=st.top()->right;
                st.pop();
            }
        }
        return result;
    }
};


/Method-3 : Using Visited Array

class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        stack<TreeNode*>st;
        vector<int>result;
        set<TreeNode*>vis;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            st.pop();

            if(temp->left==NULL && temp->right==NULL)
            {
                result.push_back(temp->val);
                continue;
            }
            if(vis.find(temp)!=vis.end())
            {
                result.push_back(temp->val);
                continue;
            }

            if(temp->right!=NULL)
            {
                st.push(temp->right);
            }
            st.push(temp);
            if(temp->left!=NULL)
            {
                st.push(temp->left);
            }
            vis.insert(temp);
        }
        return result;
    }
};
