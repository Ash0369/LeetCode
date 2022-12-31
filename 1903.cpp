//Method-1 : 

class Solution 
{
public:
    
    string largestOddNumber(string num) 
    {
        string ans="";
        string temp="";
        for(auto x:num)
        {
            int n=x-'0';
            if(x%2==0)
            {
                temp.push_back(x);
                
            }
            else
            {
                temp.push_back(x);
                if(ans.size()<temp.size())
                {
                    ans=temp;
                }
            }
        }
        
        return ans;
    }
};

//Method-2 : 


class Solution 
{
public:
    
    string largestOddNumber(string num) 
    {
        string ans="";
        string temp="";
        for(int i=num.size();i>=0;i--)
        {
            int x=num[i]-'0';
            if(x%2!=0)
            {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
