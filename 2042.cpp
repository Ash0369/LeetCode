class Solution 
{
public:
    bool areNumbersAscending(string s) 
    {
        int n=s.length();
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            if((s[i]>=97 && s[i]<=122) || s[i]==' ')
            {
                continue;
            }
            else
            {
                int start=i;
                int end=i;
                while(i<n && s[i]!=' ' && (s[i]<97 || s[i]>122))
                {
                    end++;
                    i++;
                }
                i--;
                string m=s.substr(start,end-start);
                int temp=stoi(m);
                if(temp>prev)
                {
                    prev=temp;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
