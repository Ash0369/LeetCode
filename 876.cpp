//Method-1 : O(n) Time complexity and O(n) Space Complexity


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

//Method-2 : O(1) Space Complexity

class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
