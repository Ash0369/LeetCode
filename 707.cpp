//Method-1 : Using Linked List


struct List_Node 
{
    int val;
    List_Node *next;
    List_Node *prev;
    List_Node() : val(0), next(nullptr),prev(nullptr) {}
    List_Node(int x) : val(x), next(nullptr),prev(nullptr) {}
    List_Node(int x, List_Node *next , List_Node *prev) : val(x), next(next) , prev(prev) {}
};
class MyLinkedList 
{
public:
    List_Node *dummy_head=new List_Node(-1);
    List_Node *dummy_tail=new List_Node(-1);
    int curr_size=0;
    MyLinkedList() 
    {
        dummy_head->next=dummy_tail;
        dummy_tail->prev=dummy_head;
    }

    // void print(List_Node *head)
    // {
    //     while(head->next!=NULL)
    //     {
    //         cout<<head->val<<"-> ";
    //         head=head->next;
    //     }
    //     cout<<"NULL"<<endl;
    // }
    
    int get(int index) 
    {
        if(index>=curr_size)
        {
            return -1;
        }
        List_Node *temp=dummy_head->next;
        while(index>0)
        {
            temp=temp->next;
            index--;
        }
        return temp->val;
    }
    
    void addAtHead(int val) 
    {
        List_Node *new_node=new List_Node(val);
        List_Node *temp=dummy_head->next;
        dummy_head->next=new_node;
        new_node->prev=dummy_head;
        new_node->next=temp;
        temp->prev=new_node;
        curr_size++;
    }
    
    void addAtTail(int val) 
    {
        List_Node *new_node=new List_Node(val);
        List_Node *temp=dummy_tail->prev;
        dummy_tail->prev=new_node;
        new_node->next=dummy_tail;
        temp->next=new_node;
        new_node->prev=temp;
        curr_size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index>curr_size)
        {
            return;
        }
        if(index==0)
        {
            addAtHead(val);
        }
        else if(index==curr_size)
        {
            addAtTail(val);
        }
        else
        {
            int t=index-1;
            List_Node *temp=dummy_head->next;
            while(t>0)
            {
                temp=temp->next;
                t--;
            }
            List_Node *new_node=new List_Node(val);
            List_Node *nxt=temp->next;
            temp->next=new_node;
            new_node->prev=temp;
            new_node->next=nxt;
            nxt->prev=new_node;
            curr_size++;
        }
    }
    
     void deleteAtIndex(int index) 
    {
        if(index>=curr_size)
        {
            return;
        }
        if(curr_size==1)
        {
            curr_size=0;
            dummy_head->next=dummy_tail;
            dummy_tail->prev=dummy_head;
            curr_size=0;
            return;
        }
        if(index==0)
        {
            dummy_head->next=dummy_head->next->next;
            dummy_head->next->prev=dummy_head;
            curr_size--;
            return;
        }
        if(index==curr_size-1)
        {
            dummy_tail->prev=dummy_tail->prev->prev;
            dummy_tail->prev->next=dummy_tail;
            curr_size--;
            return;
        }
        int t=index-1;
        List_Node *temp=dummy_head->next;
        while(t>0)
        {
            temp=temp->next;
            t--;
        }
        temp->next=temp->next->next;
        temp->next->prev=temp;
        curr_size--;
    }
};

//Method-2 : Using Deque


class MyLinkedList 
{
public:
    deque<int>ele;
    deque<int>helper;
    int curr_size=0;
    MyLinkedList() 
    {
        
    }
    
    int get(int index) 
    {
        if(index>=curr_size)
        {
            return -1;
        }
        while(index>0)
        {
            helper.push_back(ele.front());
            ele.pop_front();
            index--;
        }
        int val=ele.front();
        while(!helper.empty())
        {
            ele.push_front(helper.back());
            helper.pop_back();
        }
        return val;
    }
    
    void addAtHead(int val) 
    {
        ele.push_front(val);
        curr_size++;
    }
    
    void addAtTail(int val) 
    {
        ele.push_back(val);
        curr_size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index>curr_size)
        {
            return;
        }
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        if(index==curr_size)
        {
            addAtTail(val);
            return;
        }
        while(index>0)
        {
            helper.push_back(ele.front());
            ele.pop_front();
            index--;
        }
        ele.push_front(val);
        while(!helper.empty())
        {
            ele.push_front(helper.back());
            helper.pop_back();
        }
        curr_size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index>=curr_size)
        {
            return;
        }
        if(index==0)
        {
            ele.pop_front();
            curr_size--;
            return;
        }
        if(index==curr_size-1)
        {
            ele.pop_back();
            curr_size--;
            return;
        }
        while(index>0)
        {
            helper.push_back(ele.front());
            ele.pop_front();
            index--;
        }
        ele.pop_front();
        while(!helper.empty())
        {
            ele.push_front(helper.back());
            helper.pop_back();
        }
        curr_size--;
    }
};
