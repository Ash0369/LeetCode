class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string a,b,c,d;
        for(int i=0;i<s1.size();i++)
        {
            if(i%2==0)
            {
                a.push_back(s1[i]);
                b.push_back(s2[i]);
            }
            else
            {
                c.push_back(s1[i]);
                d.push_back(s2[i]);
            }
        }
      
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        
        
        if(a==b && c==d)
        {
            return true;
        }
        return false;
    }
};
