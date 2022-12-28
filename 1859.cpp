class Solution 
{
public:
    string sortSentence(string s) 
    {
        int n=s.length();
        s.push_back(' ');
        vector<string>vec(200," ");
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<=n;j++)
            {
                i++;
                if(s[j]==' ')
                {
                    char a=temp.back();
                    temp.pop_back();
                    vec[a-'0']=temp;
                    
                    break;
                }
                temp.push_back(s[j]);
            }
            i--;
        }
        string ans="";
        for(int i=1;i<200;i++)
        {
            if(vec[i]==" ")
            {
                continue;
            }
          
            ans+=vec[i];
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
        
    }
};
