//Method-1 : 

class Solution 
{
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        map<char,int>mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            string w1=words[i];
            string w2=words[i+1];
            
            for(int j=0;j<=20;j++)
            {
                if(w1.size()>j && w2.size()<=j)
                    return false;
                if(w1.size()<=j && w2.size()>j)
                    break;
                
                int c1=mp[w1[j]];
                int c2=mp[w2[j]];
                
                if(c1>c2)
                    return false;
                if(c1<c2)
                    break;
            }
        }
        return true;
    }
};


//Method-2 : 

class Solution 
{
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        map<char,char>mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i+'a';
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                words[i][j]=mp[words[i][j]];
            }
        }
        return is_sorted(words.begin(),words.end());
    }
};
