void swap(ListNode* a,ListNode* b)
{
    int c=a->val;
    a->val=b->val;
    b->val=c;
}
class Solution 
{
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        vector<ListNode*>vec;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            vec.push_back(temp);
            temp=temp->next;
        }
        swap(vec[k-1],vec[vec.size()-k]);
        return head;
    }
};
