class Solution 
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        if(sx==fx && sy==fy)
        {
            return t!=1;
        }
        int d=0;
        d=min(abs(sx-fx),abs(sy-fy));
        d=d+(max(abs(sx-fx),abs(sy-fy))-d);
        
        if(t>=d)return true;
        return false;
        
    }
};
