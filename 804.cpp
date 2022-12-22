class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string>defination{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
                                 "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string,int>mp;
        for(auto x:words)
        {
            string ans="";
            for(int i=0;i<x.size();i++)
            {
                char c=x[i];
                ans+=defination[int(c)-97];
            }
            mp[ans]++;
        }
        return mp.size();
    }
};
