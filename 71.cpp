class Solution 
{
public:
    string simplifyPath(string path)
    {
        stack<string>st;
        string ans="";
        for(int i=0;i<path.size();i++)
        {
            char c=path[i];
            if(c=='/')
            {
                int j=i+1;
                string temp="";
                while(j<path.size() && path[j]!='/')
                {
                    temp.push_back(path[j]);
                    j++;
                }
                if(temp=="..")
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                }
                else if(temp=="." || temp=="")
                {
                    continue;
                }
                else
                {
                    st.push(temp);
                }
            }
        }
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans=="")
        {
            ans.push_back('/');
        }
        return ans;
    }
};
