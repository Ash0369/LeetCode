map<Node*,Node*>mp;
Node *dfs(Node *node)
{
    Node *temp=new Node(node->val);
    mp[node]=temp;
    for(auto x:node->neighbors)
    {
        if(mp.find(x)!=mp.end())
        {
            temp->neighbors.push_back(mp[x]);
            continue;
        }
        Node *d=dfs(x);
        temp->neighbors.push_back(d);
    }
    return temp;
}
class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        mp.clear();
        if(node==NULL)
            return NULL;
        return dfs(node);
    }
};
