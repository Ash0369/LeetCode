class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int e=0;
        int c=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                e++;
            }
            else if(moves[i]=='R')
            {
                e--;
            }
            else
            {
                c++;
            }
            
        }
        
        return abs(e)+c;
    }
};
