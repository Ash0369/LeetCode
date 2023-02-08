int scor(int index,vector<string>&words,multiset<char>&st,vector<int>& score)
{
    if(index==words.size())
    {
        return 0;
    }
    //Not take
    int a=scor(index+1,words,st,score);
    
    //Try to take
    
    int b=0;
    
    string target=words[index];
    int res=-1;

    for(int i=0;i<target.size();i++)
    {
        if(st.find(target[i])==st.end())
        {
            res=i;
            break;
        }
        b=b+score[target[i]-'a'];
        st.erase(st.find(target[i]));
    }
    if(res==-1)
    {
        res=target.size();
        b+=scor(index+1,words,st,score);
    }
    else
    {
        b=0;
    }
    for(int i=0;i<res;i++)
    {
        st.insert(target[i]);
    }
    return max(a,b);
}
class Solution 
{
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        multiset<char>st(letters.begin(),letters.end());
        return scor(0,words,st,score);
    }
};
