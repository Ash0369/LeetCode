//Method-1 : 

class Solution 
{
public:
    bool checkString(string s) 
    {
        bool b=false;
        for(auto x:s)
        {
            if(x=='a' && b==true)
            {
                return false;
            }
            if(x=='b')
                b=true;
        }
        return true;
    }
};

//Method-2 : 

class Solution 
{
public:
    bool checkString(string s) 
    {
       return is_sorted(s.begin(),s.end());
    }
};
