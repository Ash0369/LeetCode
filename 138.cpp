//Method-1 : Using Map

Node* copy(Node* head,map<Node*,Node*>&mp)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(mp.find(head)==mp.end())
    {
        Node* temp=new Node(head->val);
        mp[head]=temp;
        mp[head]->next=copy(head->next,mp);
        mp[head]->random=copy(head->random,mp);
    }
    return mp[head];
}
class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        map<Node*,Node*>mp;
        return copy(head,mp);
    }
};
