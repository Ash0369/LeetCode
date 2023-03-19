struct Node
{
    Node *links[26];
    bool flag=false;
    
    bool exist(char c)
    {
        if(links[c-'a']==NULL)
        {
            return false;
        }
        return true;
    }
    void create(char c,Node *node)
    {
        links[c-'a']=node;
    }
    Node *next_link(char c)
    {
        return links[c-'a'];
    }
};

bool dfs(int i,string &word,Node *base)
{
    if(i==word.size())
    {
        if(base->flag==true)
        {
            return true;
        }
        return false;
    }
    if(word[i]=='.')
    {
        for(char c='a';c<='z';c++)
        {
            if(base->exist(c)==true)
            {
                bool res=dfs(i+1,word,base->next_link(c));
                if(res)
                {
                    return true;
                }
            }
        }
        return false;
    }
    if(base->exist(word[i])==false)
    {
        return false;
    }
    return dfs(i+1,word,base->next_link(word[i]));
}
class WordDictionary 
{
public:
    Node *root;
    WordDictionary() 
    {
        root=new Node();
    }
    
    void addWord(string word) 
    {
        Node *base=root;
        for(int i=0;i<word.size();i++)
        {
            if(base->exist(word[i])==false)
            {
                base->create(word[i],new Node());
            }
            base=base->next_link(word[i]);
        }
        base->flag=true;
    }
    
    bool search(string word) 
    {
        Node *base=root;
        return dfs(0,word,base);
    }
};
