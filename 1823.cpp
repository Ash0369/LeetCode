//Methd-1 : O(n) Time and Space Complexity , Using Deque

class Solution 
{
public:
    int findTheWinner(int n, int k) 
    {
       deque<int>dq;
       for(int i=1;i<=n;i++)
       {
            dq.push_back(i);
       }
       while(dq.size()!=1)
       {
            int r=k-1;
            while(r>0)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                r--;
            }
            dq.pop_front();
       }
       return dq.front();

    }
};

//Method-2 : O(n) Time and Space Complexity , Using Recurssion

int ans;
void game(int curr,int k,vector<int>&vec)
{
    if(vec.size()==1)
    {
        ans=vec[0];
        return;
    }
    curr=(curr+k)%vec.size();
    vec.erase(vec.begin()+curr);
    game(curr,k,vec);
}
class Solution 
{
public:
    int findTheWinner(int n, int k) 
    {
        ans=0;
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            vec.push_back(i);
        }
        game(0,k-1,vec);
        return ans;
    }
};
