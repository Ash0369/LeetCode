//Method-1 : Time Complexity O(n) and Space Complexity O(n)

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

//Method-2 : Two Pointers,Time Complexity O(n) and Space Complexity O(1)

class Solution 
{
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* first=head;
        while(k>1)
        {
            fast=fast->next;
            first=first->next;
            k--;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        int c;
        c=first->val;
        first->val=slow->val;
        slow->val=c;
        return head;
    }
};
