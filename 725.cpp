class Solution 
{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }
        vector<ListNode*>result;
        temp=head;
        if(length<=k)
        {
            while(length>0)
            {
                ListNode* to_push=temp;
                temp=temp->next;
                to_push->next=NULL;
                result.push_back(to_push);
                length--;
                k--;
            }
            while(k>0)
            {
                result.push_back(NULL);
                k--;
            }
        }
        else
        {
            int n=length%k;
            int size=(length/k);

            while(n>0)
            {
                int iter=size;
                ListNode* to_push=temp;
                while(iter>0)
                {
                    temp=temp->next;
                    iter--;
                }
                ListNode* nxt=temp->next;
                temp->next=NULL;
                result.push_back(to_push);
                temp=nxt;
                n--;
            }

            int rem=k-(length%k);

            while(rem>0)
            {
                int iter=size-1;
                ListNode* to_push=temp;
                while(iter>0)
                {
                    temp=temp->next;
                    iter--;
                }
                ListNode* nxt=temp->next;
                temp->next=NULL;
                result.push_back(to_push);
                temp=nxt;
                rem--;
            }
        }
        return result;
    }
};
