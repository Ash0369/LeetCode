//Method -1 : 1st Hard Q of Leet Code which i solved on my own without any help by purely my method :) 

class Solution 
{
public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        stack<pair<TreeNode*,int>>st;
        int index=0;
        while(index<traversal.length() && traversal[index]!='-')
        {
            index++;
        }
        TreeNode *root=new TreeNode(stoi(traversal.substr(0,index)));
        st.push(make_pair(root,0));
        int count=0;
        int n=traversal.length();
        for(int i=index;i<n;i++)
        {
            if(traversal[i]=='-')
            {
                count++;
        
            }
            else
            {
                int intial=i;
                int size=0;
                while(i<traversal.size() && traversal[i]!='-')
                {
                    size++;
                    i++;
                }
                i--;
                TreeNode *temp=new TreeNode(stoi(traversal.substr(intial,size)));
                while(st.size()>=1 && count<=st.top().second)
                {
                    st.pop();
                }
                if(count>st.top().second)
                {
                    
                    if(st.top().first->left==NULL)
                    {
                        st.top().first->left=temp;
                    }
                    else
                    {
                        st.top().first->right=temp;
                    }
                }
                st.push(make_pair(temp,count));
                count=0;
            }
        }
        return root;
    }
};
