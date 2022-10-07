//Method-1 : Using reverse

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


//Method-2 : Using Stack

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
        stack<vector<int>>s;
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
            s.push(temp);
            temp.clear();
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};


//Method-3 : Optimized Way


class Solution 
{
public:
    int depth(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        
        int d=depth(root);
        vector<vector<int>>ans(d,vector<int>({}));
        int i=0;
        
        queue<TreeNode*>st;
        st.push(root);
        ans[d-1].push_back(root->val);
        st.push(NULL);
        d--;
        
        while(!st.empty())
        {
            TreeNode *t=st.front();
            st.pop();
            if(t)
            {
                 if(t->left)
                 {
                     ans[d-1].push_back(t->left->val);
                     st.push(t->left);
                 }
                     
                 if(t->right)
                 {
                     st.push(t->right);
                     ans[d-1].push_back(t->right->val);
                 }
            }
            else
            {
                if(st.empty())
                    break;
                d--;
                st.push(NULL);
            }
        }
        return ans;
    }
};
