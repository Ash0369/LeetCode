class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n1=a.length();
        int n2=b.length();
        string res="";
        int carry=0;
        n1--;
        n2--;
        while(n1>=0 || n2>=0 || carry>0)
        {
            int al=0;
            int bl=0;
            
            if(n1>=0)
            {
                if(a[n1]=='1')
                {
                    al=1;
                }
                else
                {
                    al=0;
                }
                n1--;
            }
            else
            {
                al=0;
            }

            if(n2>=0)
            {
                if(b[n2]=='1')
                {
                    bl=1;
                }
                else
                {
                    bl=0;
                }
                n2--;
            }
            else
            {
                bl=0;
            }
            int sum=al+bl+carry;
            if(sum==0)
            {
                carry=0;
                res=res+'0';
            }
            else if(sum==1)
            {
                carry=0;
                res=res+'1';
            }
            else
            {
                carry=1;
                if(sum==2)
                {
                    res=res+'0';
                }
                else
                {
                    res=res+'1';
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
