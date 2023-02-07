bool check(vector<int>&mp1,vector<int>&mp2)
{
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if(mp1[i]>0)
        {
            cnt++;
        }
        if(mp2[i]>0)
        {
            cnt--;
        }
    }
    return cnt==0;
}
class Solution 
{
public:
    bool isItPossible(string word1, string word2) 
    {
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        
        for(int i=0;i<word1.size();i++)
        {
            mp1[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++)
        {
            mp2[word2[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(mp1[i]==0 || mp2[j]==0)
                {
                    continue;
                }
                int x=mp1[i];
                int y=mp2[j];
                
                mp2[j]--;
                mp2[i]++;
                mp1[i]--;
                mp1[j]++;
                

                if(check(mp1,mp2))
                    return true;
                mp2[j]++;
                mp2[i]--;
                mp1[i]++;
                mp1[j]--;
                 
            } 
            
        }
        
        return false;
    }
};
