//Method-1 : O(n*n)


class Solution 
{
public:
    int maxDistance(vector<int>& colors) 
    {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(colors[i]!=colors[j])
                {
                    ans=max(ans,abs(i-j));
                }
            }
        }
        return ans;
        
    }
};

//Method-2 : 

//https://leetcode.com/problems/two-furthest-houses-with-different-colors/discuss/1589029/Constant-Space

//O(n)

class Solution 
{
public:
    int maxDistance(vector<int>& colors) 
    {
        int n=colors.size();
        int left=0;
        int right=n-1;
        while(colors[0]==colors[right])
            right--;
        while(colors[n-1]==colors[left])
            left++;
        
        return max(right,n-1-left);
        
    }
};
