//Method-1 Pop costly

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x)
    {
        s1.push(x);
    }
    
    int pop() 
    {
        int n=s1.size();
        while(n>1)
        {
            s2.push(s1.top());
            s1.pop();
            n--;
        }   
        int val=s1.top();
        s1.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }
    
    int peek() 
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }   
        int val=s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return val; 
    }
    
    bool empty()
    {
       if(s1.empty())
       {
        return true;
       } 
       return false;
    }
};

//Method-2 push costly

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() 
    {
        int val=s1.top();
        s1.pop();
        return val;
    }
    
    int peek() 
    {
        return s1.top(); 
    }
    
    bool empty()
    {
       if(s1.empty())
       {
        return true;
       } 
       return false;
    }
};
