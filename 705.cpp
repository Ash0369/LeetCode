class MyHashSet 
{
public:
    vector<bool>vec;
    MyHashSet() 
    {
        vector<bool>temp(1000001,false);
        vec=temp;
    }
    
    void add(int key) 
    {
        vec[key]=true;
    }
    
    void remove(int key) 
    {
        vec[key]=false;
    }
    
    bool contains(int key) 
    {
        return vec[key];
    }
};
