class Solution 
{
public:
    int splitNum(int num) 
    {
        string a="";
        string b="";
        string s=to_string(num);
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            a.push_back(s[i]);
            i++;
            if(i<s.size())
            {
                b.push_back(s[i]);
            }
        }
        int num1=stoi(a);
        int num2=stoi(b);
        return num1+num2;
    }
};
