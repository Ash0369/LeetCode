//Method-1 : Using Dequeue

class MyCircularDeque 
{
public:
    deque<int>dq;
    int size;
    MyCircularDeque(int k) 
    {
        size=k;
    }
    
    bool insertFront(int value) 
    {
        if(dq.size()>=size)
        {
            return false;
        }
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(dq.size()>=size)
        {
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() 
    {
        if(dq.empty())
        {
            return false;
        }
        dq.pop_front();
        return true;
    }
    
    bool deleteLast() 
    {
        if(dq.empty())
        {
            return false;
        }
        dq.pop_back();
        return true;
    }
    
    int getFront() 
    {
        if(dq.empty())
        {
            return -1;
        }
        return dq.front();
    }
    
    int getRear() 
    {
        if(dq.empty())
        {
            return -1;
        }
        return dq.back();
    }
    
    bool isEmpty() 
    {
        if(dq.empty())
        {
            return true;
        }
        return false;
    }
    
    bool isFull() 
    {
        if(dq.size()==size)
        {
            return true;
        }
        return false;
    }
};


//Method-2 : Using Doubly Linked List

struct List_Node {
    int val;
    List_Node *next;
    List_Node *prev;
    List_Node() : val(0), next(nullptr),prev(nullptr) {}
    List_Node(int x) : val(x), next(nullptr),prev(nullptr) {}
    List_Node(int x, List_Node *next,List_Node*prev) : val(x), next(next),prev(prev) {}
};

class MyCircularDeque 
{
public:

    List_Node* head=new List_Node(0);
    List_Node* tail=new List_Node(0);
    int size=0;
    int max_size;
    MyCircularDeque(int k) 
    {
        max_size=k;   
    }
    
    bool insertFront(int value) 
    {
        if(isFull())
        {
            return false;
        }
        List_Node* temp=new List_Node(value);
        if(isEmpty())
        {
            head=temp;
            tail=temp;
            head->prev=NULL;
            tail->prev=NULL;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
        {
            return false;
        }
        List_Node* temp=new List_Node(value);

        if(isEmpty())
        {
            head=temp;
            tail=temp;
            head->prev=NULL;
            tail->prev=NULL;
        }
        else
        {
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        size++;
        return true;

    }
    
    bool deleteFront() 
    {
        if(isEmpty())
        {
            return false;
        }
        List_Node* todel=head;
        head=head->next;
        delete(todel);
        size--;
        return true;
    }
    
    bool deleteLast() 
    {
        if(isEmpty())
        {
            return false;
        }
        List_Node* todel=tail;
        tail=tail->prev;
        delete(todel);
        size--;
        return true;
    }
    
    int getFront() 
    {
        if(isEmpty())
        {
            return -1;
        }
        return head->val;
    }
    
    int getRear() 
    {
        if(isEmpty())
        {
            return -1;
        }
        return tail->val;
    }
    
    bool isEmpty() 
    {
        if(size==0)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() 
    {
        if(size==max_size)
        {
            return true;
        }
        return false;
    }
};
