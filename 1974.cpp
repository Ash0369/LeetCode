class Solution 
{
public:
    int minTimeToType(string word) 
    {
        int curr=0;
        int time=0;
        for(auto x:word)
        {
            int i=x-'a';
            if(i>=curr)
            {
                time=time+min(i-curr,curr+26-i);
            }
            else 
            {
                time=time+min(curr-i,i+26-curr);
            }
            curr=i;
            
        }
        return time+word.size();
    }
};
