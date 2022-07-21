//Method-1 : Using set

class SmallestInfiniteSet 
{
public:
    set<int>st;
    int k=0;
    SmallestInfiniteSet() 
    {
    }
    
    int popSmallest() 
    {
        if(!st.empty())
        {
            int a=*st.begin();
            st.erase(a);
            return a;
        }
        k++;
        return k;
    }
    
    void addBack(int num) 
    {
        if(num<=k)
        {
            st.insert(num);  
        }
        
    }
};
