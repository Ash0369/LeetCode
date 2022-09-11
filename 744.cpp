char binary_search(vector<char>& letters, char target,int l,int r)
{
    if(l>r)
    {
        if(l<letters.size())
        {
            return letters[l];
        }
        return letters[0];
    }
    int index=(l+r)/2;
    if(letters[index]>target)
    {
        return binary_search(letters,target,l,index-1);
    }
    return binary_search(letters,target,index+1,r);
}
class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        return binary_search(letters,target,0,letters.size()-1);
    }
};
