class Solution 
{
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        queue<TreeNode*>st;
        int level=0;
        st.push(root);
        while(!st.empty())
        {
            int n=st.size();
            int fix=(level%2==0)? INT_MIN:INT_MAX;
            for(int i=0;i<n;i++)
            {
                
                if(level%2==0 && st.front()->val<=fix)
                    return false;
                if(level%2!=0 && st.front()->val>=fix)
                    return false;
                if(level%2==(st.front()->val)%2)
                    return false;
                if(st.front()->left)
                    st.push(st.front()->left);
                if(st.front()->right)
                    st.push(st.front()->right);
                
                fix=st.front()->val;
                st.pop();
            }
            level++;
        }
        return true;
    }
};
