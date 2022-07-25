class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        vector<ListNode*>ele;
        while(head!=NULL)
        {
            ele.push_back(head);
            head=head->next;
        }
        return ele[ele.size()/2];
    }
};
