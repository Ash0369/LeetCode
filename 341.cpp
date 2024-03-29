/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator 
{
public:
    vector<NestedInteger>v;
    vector<int>ele;
    void dfs(vector<NestedInteger>&v)
    {
        for(auto x:v)
        {
            if(x.isInteger())
            {
                ele.push_back(x.getInteger());
            }
            else{
                dfs(x.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        v=nestedList;
        dfs(nestedList);
        reverse(ele.begin(),ele.end());
    }
    
    int next() 
    {
        int v=ele.back();
        ele.pop_back();
        return v;
    }
    
    bool hasNext() 
    {
        return ele.size()>0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
