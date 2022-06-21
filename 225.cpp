//Pop Operation costly

class MyStack 
{
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() 
    {
        
    }
    
    void push(int x)
    {
        q1.push(x);  
    }
    
    int pop() 
    {
        int n=q1.size();
        n=n-1;
        while(n--)
        {
            q2.push(q1.front());
            q1.pop();
        } 
        int x=q1.front();
        q1.pop();

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    int top() 
    {
        int n=q1.size();
        n=n-1;
        while(n--)
        {
            q2.push(q1.front());
            q1.pop();
        } 
        int x=q1.front();
        q1.pop();
        q2.push(x);

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    bool empty() 
    {
       if(q1.empty())
       {
            return true;
       } 
       return false;
    }
};

//Making push operation costly
class MyStack 
{
public:
    queue<int>q1;
    queue<int>q2;
    queue<int>q;
    MyStack() 
    {
        
    }
    
    void push(int x)
    {
        q2.push(x);  
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        //Swap queue
        q=q1;
        q1=q2;
        q2=q;

    }
    
    int pop() 
    {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
       if(q1.empty())
       {
            return true;
       } 
       return false;
    }
};
