class Solution 
{
public:
    bool isValidSerialization(string preorder) 
    {
        stringstream s(preorder);
        int count=1; //Taking root's parent
        string word;
        while(getline(s,word,','))
        {
            
            if(count<=0)
                return false; //Any time it cannot go below or equal to 0
            if(word!="#")
            {
                count=count+2;//We will get 2 its child further
                count--; //Node we got is child of someone
            }
            else if(word=="#")
            {
                count--; //As its NULL we  not got child what we counted 
            }
            
        }
        
        return count==0;
    }
};
