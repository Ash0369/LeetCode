class MyHashMap 
{
public:
    vector<int>vec;
    MyHashMap() 
    {
        vector<int>temp(1000001,INT_MAX);
        vec=temp;
    }
    
    void put(int key, int value) 
    {
        vec[key]=value;
    }
    
    int get(int key) 
    {
        if(vec[key]==INT_MAX)
        {
            return -1;
        }
        return vec[key];
    }
    
    void remove(int key) 
    {
        vec[key]=INT_MAX;
    }
};
