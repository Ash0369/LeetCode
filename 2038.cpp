class Solution 
{
public:
    bool winnerOfGame(string colors) 
    {
        int n=colors.size();
        int a=0;
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(colors[i]=='A')
            {
                int cnt=0;
                while(i<n && colors[i]=='A')
                {
                    i++;
                    cnt++;
                }
                a+=max(0,cnt-2);
                i--;
            }
            if(colors[i]=='B')
            {
                int cnt=0;
                while(i<n && colors[i]=='B')
                {
                    i++;
                    cnt++;
                }
                b+=max(0,cnt-2);
                i--;
            }
        }
        if(a>b)
        {
            return true;
        }
        return false;
    }
};
