struct List_Node {
    int val;
    List_Node *next;
    List_Node() : val(0), next(nullptr) {}
    List_Node(int x) : val(x), next(nullptr) {}
    List_Node(int x, List_Node *next) : val(x), next(next) {}
};
class MyCircularQueue {
public:
    List_Node* ptr;
    List_Node* headptr;
    int max_size;
    int size=0;
    MyCircularQueue(int k) 
    {
        max_size=k;
    }
    
    bool enQueue(int value) 
    {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            List_Node* head=new List_Node(value);
            ptr=head;
            headptr=head;
        }
        else
        {
            List_Node* temp=new List_Node(value);
            ptr->next=temp;
            ptr=ptr->next;
        }
        size++;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty())
        {
            return false;
        }
        List_Node* todel=headptr;
        headptr=headptr->next;
        size--;
        delete(todel);
        return true;
    }
    
    int Front() 
    {
        if(isEmpty())
        {
            return -1;
        }
        return headptr->val;
    }
    
    int Rear() 
    {
        if(isEmpty())
        {
            return -1;
        }
        return ptr->val;
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
        if(size>=max_size)
        {
            return true;
        }
        return false;
    }
};
