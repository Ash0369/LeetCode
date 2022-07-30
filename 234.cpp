//Method-1 : using Stack , O(n) Time and Space Complexity

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty())
        {
            if(temp->val!=st.top())
            {
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};
