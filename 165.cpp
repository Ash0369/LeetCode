class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int i=0;
        int j=0;
        for(;i<version1.length() || j<version2.length();i++,j++)
        {
            string a="0";
            while(i<version1.length() && version1[i]!='.')
            {
                a.push_back(version1[i]);
                i++;
            }
            
            string b="0";
            while(j<version2.length() && version2[j]!='.')
            {
                b.push_back(version2[j]);
                j++;
            }
            
            int n1=stoi(a);
            int n2=stoi(b);
            
            if(n1>n2)
                return 1;
            if(n2>n1)
                return -1;
        }
        return 0;
        
    }
};
