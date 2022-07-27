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
