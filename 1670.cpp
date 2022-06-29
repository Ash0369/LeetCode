class FrontMiddleBackQueue {
public:
    deque<int>q1;
    deque<int>q2;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q1.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n=q1.size();
        for(int i=1;i<=(n/2);i++)
        {
            q2.push_back(q1.front());
            q1.pop_front();
        }
        q1.push_front(val);
        while(!q2.empty())
        {
            q1.push_front(q2.back());
            q2.pop_back();
        }
    }
    
    void pushBack(int val) {
        q1.push_back(val);
    }
    
    int popFront() {
        if(q1.empty())
        {
            return -1;
        }
        int val=q1.front();
        q1.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(q1.empty())
        {
            return -1;
        }
        int val;
        int n=q1.size();
        for(int i=1;i<=(n/2);i++)
        {
            q2.push_back(q1.front());
            q1.pop_front();
        }
        if(n%2!=0)
        {
            val=q1.front();
            q1.pop_front();
        }
        else
        {
            val=q2.back();
            q2.pop_back();
        }
        while(!q2.empty())
        {
            q1.push_front(q2.back());
            q2.pop_back();
        }
        return val;
    }
    
    int popBack() {
        if(q1.empty())
        {
            return -1;
        }
        int val=q1.back();
        q1.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
