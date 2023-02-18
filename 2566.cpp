class Solution 
{
public:
    int minMaxDifference(int num) 
    {
        string s=to_string(num);
        char c1=s[0];
        char c2=s[0];
        int i=0;
        while(i<s.size() && s[i]=='9')
        {
            i++;
        }
        if(i!=s.size())
        {
            c1=s[i];
        }
        i=0;
        while(i<s.size() && s[i]=='0')
        {
            i++;
        }
        if(i!=s.size())
        {
            c2=s[i];
        }
        string mx=s;
        string mn=s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c1)
            {
                mx[i]='9';
            }
            if(s[i]==c2)
            {
                mn[i]='0';
            }
            
        }
        return stoi(mx)-stoi(mn);
        
    }
};
