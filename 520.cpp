class Solution 
{
public:
    bool detectCapitalUse(string word) 
    {
        string fix=word;
        transform(word.begin(),word.end(),word.begin(),::toupper);
        if(word==fix)
            return true;
        transform(word.begin(),word.end(),word.begin(),::tolower);
        if(word==fix)
            return true;
        if(isupper(fix[0]))
        {
            for(int i=1;i<fix.size();i++)
            {
                if(isupper(fix[i]))
                    return false;
            }
        }
        else if(islower(fix[0]))
            return false;
        return true;
        
    }
};
