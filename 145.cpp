//Method-1: Recursive

vector<int>result;
void postorder(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    result.push_back(root->val);

}
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        result.clear();
        postorder(root);
        return result;
    }
};


//Method-2 : Iteratative way using visited array

class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
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
             st.push(temp);
            if(temp->right!=NULL)
            {
                st.push(temp->right);
            }
           
            if(temp->left!=NULL)
            {
                st.push(temp->left);
            }
            vis.insert(temp);
        }
        return result;
    }
};

//Methd-3 : Iterative way

