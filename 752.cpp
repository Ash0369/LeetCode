char add(char c)
{
    if(c!='9')
    {
        return ((c-'0')+1)+'0';
    }
    return '0';
    
}
char sub(char c)
{
    if(c!='0')
    {
        return ((c-'0')-1)+'0';
    }
    return '9';
}
class Solution 
{
public:
    int openLock(vector<string>& deadends, string target) 
    {
        set<string>st(deadends.begin(),deadends.end());
        map<string,int>mp;
        mp["0000"]=0;
        queue<string>q;
        int op=0;
        q.push("0000");
        while(!q.empty())
        {
            int n=q.size();
            for(int j=0;j<n;j++)
            {
                string curr=q.front();
                q.pop();
                if(st.find(curr)!=st.end())
                {
                    continue;
                }
                if(curr==target)
                {
                    return op;
                }
                
                for(int i=0;i<4;i++)
                {
                    char c=curr[i];
                    curr[i]=add(curr[i]);
                    if(mp.find(curr)==mp.end())
                    {
                        mp[curr]=op+1;
                        q.push(curr);
                    }
                 
                    curr[i]=sub(c);
                    if(mp.find(curr)==mp.end())
                    {
                        mp[curr]=op+1;
                        q.push(curr);
                    }
                    curr[i]=c;
                }           
            }
                               
            op++;
        }
        return -1;
    }
};
