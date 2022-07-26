//Method-1 : Brute Force

class Solution 
{
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>result;
        while(head!=NULL)
        {
            ListNode*ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->val>head->val)
                {
                    result.push_back(ptr->val);
                    break;
                }
                ptr=ptr->next;
            }
            if(ptr==NULL)
            {
                result.push_back(0);
            }
            head=head->next;
        }
        return result;
    }
};
