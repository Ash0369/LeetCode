//Method-1 : Using Priority Queue : Time Complexity O(n*log(n)) and Space Complexity O(n)

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        priority_queue<int>pq;
        for(auto x:nums)
        {
            pq.push(x);
        }
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        return (a-1)*(b-1);
    }
};

//Method-2 : Using Vector : Time Complexity O(n*log(n)) and Space Complexity O(1)

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};
