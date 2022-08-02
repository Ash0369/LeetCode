//Method-1 : First creating an array and finding it's subsequence of length==k 


vector<vector<int>>result;
void combination(vector<int>&curr,int k,vector<int>&nums,int index)
{
    if(curr.size()==k)
    {
        result.push_back(curr);
        return;
    }
    if(nums.size()<=index  || curr.size()>k)
    {
        return;
    }
    combination(curr,k,nums,index+1);
    curr.push_back(nums[index]);
    combination(curr,k,nums,index+1);
    curr.pop_back();
    
}
class Solution 
{
public:
    vector<vector<int>>combine(int n, int k) 
    {
        result.clear();
        vector<int>curr;
        for(int i=1;i<=n;i++)
        {
           curr.push_back(i);
        }
        vector<int>temp;
        combination(temp,k,curr,0);
        return result;
    }
};


//Method-2 :

vector<vector<int>>result;
void combination(int k,int n,vector<int>&curr,int index)
{
    if(curr.size()==k)
    {
        result.push_back(curr);
        return;
    }
    if(index>n)
    {
        return;
    }
    combination(k,n,curr,index+1);
    curr.push_back(index);
    combination(k,n,curr,index+1);
    curr.pop_back();
}

class Solution 
{
public:
     vector<vector<int>>combine(int n, int k)
    {
        result.clear();
        vector<int>curr;
        for(int i=1;i<=n;i++)
        {
            curr.push_back(i);
            combination(k,n,curr,i+1);
            curr.pop_back();
        }
        return result;
    }
};
