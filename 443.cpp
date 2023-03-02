class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        string ans="";
        int n=chars.size();
        int pos=0;
        for(int i=0;i<n;i++)
        {
            char c=chars[i];
            i++;
            int cnt=1;
            while(i<n && chars[i]==c)
            {
                cnt++;
                i++;
            }
            i--;
            chars[pos]=chars[i];
            pos++;
            string temp=to_string(cnt);
            if(cnt!=1)
            {
                for(auto x:temp)
                {
                    chars[pos]=x;
                    pos++;
                }
            }
        }
        return pos;
    }
};
