class Solution 
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        vector<vector<int>>ans;
        vector<int>temp;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            int k=st.size();
            for(int i=0;i<k;i++)
            {
                TreeNode *t=st.front();
                temp.push_back(t->val);
                if(t->left)
                    st.push(t->left);
                if(t->right)
                    st.push(t->right);
                st.pop();
            }
            ans.push_back(temp);
            temp.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
