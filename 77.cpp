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

class Solution 
{
public:
    vector<vector<int>>result;
    void combination(int index, int k,vector<int>&curr,int n)
    {
        if(curr.size()==k)    // base case
        {
            result.push_back(curr);
            return;
        }
        for(int i=index;i<n+1;i++)
        {
            curr.push_back(i);  //consider the current element i
            combination(i+1,k,curr,n); // generate combinations
            curr.pop_back(); //proceed to next element
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>current;
        combination(1,k,current,n);
        return result; //return answer
    }
};
