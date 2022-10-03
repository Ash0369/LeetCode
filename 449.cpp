//Method-1 : Optimal

class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(!root)
            return "";
        
        return to_string(root->val)+'-'+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    
    TreeNode *make_tree(TreeNode *root,int value)
    {
        if(root==NULL)
        {
            TreeNode *temp=new TreeNode(value);
            return temp;
        }
        if(root->val<value)
        {
            root->right=make_tree(root->right,value);
        }
        else
        {
            root->left=make_tree(root->left,value);
        }
        return root;
    }
    TreeNode* deserialize(string data) 
    {
        if(data.size()==0 || data[0]=='*')
            return NULL;
        stringstream s(data);
        string d;
        TreeNode *root=NULL;
        while(getline(s,d,'-'))
            root=make_tree(root,stoi(d));
        
        return root;
    }
};

//Method-2 : (High Space)

class Codec 
{
public:
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
