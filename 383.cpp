//Method-1 : 

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char,int>mp1;
        map<char,int>mp2;
        
        for(auto c:ransomNote)
        {
            mp1[c]++;
        }
        for(auto c:magazine)
        {
            mp2[c]++;
        }

        for(auto x:mp1)
        {
            if(mp2.find(x.first)!=mp2.end())
            {
                if(mp2[x.first]<x.second)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

//Method-2: 

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int arr[26]={0};
        for(auto x:magazine)
        {
            arr[int(x)-97]++;
        }
        for(auto x:ransomNote)
        {
            arr[int(x)-97]--;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]<0)
            {
                return false;
            }
        }
        return true;
    }
};
