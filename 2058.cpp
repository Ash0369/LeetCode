class Solution 
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>pos;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* aftr=NULL;
        int count=0;
        while(curr!=NULL)
        {
            aftr=curr->next;
            if(prev!=NULL && aftr!=NULL)
            {
                if((curr->val>prev->val && curr->val>aftr->val) || (curr->val<prev-> val  && curr->val<aftr->val))
                {
                    pos.push_back(count);
                }
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        vector<int>result;
        if(pos.size()<2)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int min_val=INT_MAX;
        for(int i=0;i<pos.size()-1;i++)
        {
            if(abs(pos[i]-pos[i+1])<min_val)
            {
                min_val=abs(pos[i]-pos[i+1]);
            }
        }
        result.push_back(min_val);
        result.push_back(pos[pos.size()-1]-pos[0]);
        return result;
    }
};
