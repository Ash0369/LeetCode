//Method-1 : 


class Solution 
{
public:
    string gcdOfStrings(string str1, string str2) 
    {
        string y;
        int n1=str1.size();
        int n2=str2.size();
        
        if(n1<=n2)
        {
            y=str1;
        }
        else
        {
            y=str2;
        }
        
        while(y.size()>0)
        {
            string x=y;
            bool a=false;
            bool b=false;
            while(x.size()<=n1 || x.size()<=n2)
            {
                if(x==str2)
                {
                    b=true;
                }
                if(x==str1)
                {
                    a=true;
                }
                
                if(a && b)
                {
                    return y;
                }
                x=x+y;
            }
            y.pop_back();
        }
        return "";
    }
};


//Method-2 : 

class Solution 
{
public:
    string gcdOfStrings(string str1, string str2) 
    {
        int n1=str1.length();
        int n2=str2.length();
        if(str1+str2==str2+str1)
        {
            return str1.substr(0,__gcd(n1,n2));
        }
        return "";
    }
};
