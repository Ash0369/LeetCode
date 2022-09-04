class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root==NULL)
        {
            return "";
        }
        queue<TreeNode *>q;
        q.push(root);
        string res="";
        while(!q.empty())
        {
            
            TreeNode *r=q.front();
            q.pop();
            if(r==NULL)
            {
                res.append("*,");
                continue;
            }
            res.append(to_string(r->val)+',');     
            q.push(r->left);
            q.push(r->right);
            
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size()==0)
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode *>q;
        TreeNode *root =new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
          
              TreeNode *t=q.front();
              q.pop();
              getline(s,str,',');
              if(str=="*")
              {
                  t->left=NULL;
              }
              else
              {
                  TreeNode *temp=new TreeNode(stoi(str));
                  t->left=temp;
                  q.push(temp);
              }
              getline(s,str,',');
              if(str=="*")
              {
                  t->right=NULL;
              }
              else
              {
                  TreeNode *temp=new TreeNode(stoi(str));
                  t->right=temp;
                  q.push(temp);
              }
        }
        
        return root;
    }
};
