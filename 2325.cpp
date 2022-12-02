class Solution 
{
public:
    string decodeMessage(string key, string message) 
    {
        map<char,char>mp;
        char base='a';
        for(int i=0;i<key.size();i++)
        {
            if(key[i]==' ')
                continue;
            if(mp.find(key[i])==mp.end())
            {
                mp[key[i]]=base;
                base++;
            }
        }
        
        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
                continue;
            message[i]=mp[message[i]];
        }
        return message;
    }
};
