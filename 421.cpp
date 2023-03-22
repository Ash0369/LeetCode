struct Node
{
    Node *links[2];
    bool if_exist(int a)
    {
        if(links[a]==NULL)
        {
            return false;
        }
        return true;
    }
    Node* get(int a)
    {
        return links[a];
    }
    void put(int a,Node *node)
    {
        links[a]=node;
    }
};
class Trie
{
    public:
    Node *root;
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->if_exist(bit)==false)
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int get_max(int num)
    {
        Node *node=root;
        int maxnum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->if_exist(1-bit)==false)
            {
                node=node->get(bit);
            }
            else
            {
                maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
            
        }
        return maxnum;
    }
};
class Solution 
{
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie trie;
        for (auto x:nums)
        {
            trie.insert(x);
        }
        int ans=0;
        for(auto it:nums)
        {
            ans=max(ans,trie.get_max(it));
        }
        return ans;
    }
};
