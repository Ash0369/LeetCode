//Method-1 Using Linked List and Map

struct List_Node 
{
    int key;
    int val;
    List_Node *next;
    List_Node *prev;
    List_Node() : val(0),key(0), next(nullptr),prev(nullptr) {}
    List_Node(int x,int y) : key(x),val(y),next(nullptr),prev(nullptr) {}
    List_Node(int x,int y, List_Node *next,List_Node *prev) : key(x),val(y),next(next),prev(prev) {}
};


class LRUCache 
{
public:
    int max_size;
    int current_size=0;
    map<int,List_Node*>mp;
    List_Node *dummy_head=new List_Node(-1,-1);
    List_Node *dummy_tail=new List_Node(-1,-1);
    LRUCache(int capacity) 
    {
        max_size=capacity;
        dummy_head->next=dummy_tail;
        dummy_tail->prev=dummy_head;
    }

    void move(List_Node *&temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        temp->prev=dummy_tail->prev;
        temp->next=dummy_tail;
        dummy_tail->prev->next=temp;
        dummy_tail->prev=temp;
    }

    void create(int key,int value)
    {
        List_Node* node=new List_Node(key,value);
        node->prev=dummy_tail->prev;
        dummy_tail->prev->next=node;
        node->next=dummy_tail;
        dummy_tail->prev=node;
        mp[key]=node;  
    }
    
    int get(int key) 
    {  
        if(mp.find(key)!=mp.end())
        {
            List_Node* temp=mp[key];
            int a=temp->val;
            move(temp);
            return a;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val=value;
            move(mp[key]);
            return;
        }
        if(current_size<max_size)
        {
            create(key,value);
            current_size++;
        }
        else
        {
            mp.erase(dummy_head->next->key);
            dummy_head->next=dummy_head->next->next;
            dummy_head->next->prev=dummy_head;
            create(key,value);
        }
    }
};


//Method-2 : Using STL List and Map

class LRUCache 
{
public:
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    list<pair<int,int>>l;
    int max_capacity;

    LRUCache(int capacity) 
    {
        max_capacity=capacity;
    }
    int get(int key) 
    {  
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;
        
    }
    
    void put(int key, int value) 
    {
       if(mp.find(key)!=mp.end())
       {
            mp[key]->second=value;
            l.splice(l.begin(),l,mp[key]);
            return;
       }
       if(l.size()==max_capacity)
       {
            mp.erase(l.back().first);
            l.pop_back();
       }
       l.push_front(make_pair(key,value));
       mp[key]=l.begin();
    }
};
