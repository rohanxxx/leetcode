/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 /*
    given a nested list of int nestedList
    each element is either an int or a list whose element may also be int or other lists
 */
class Solution {
public:
    //bool isInteger() const; 
    //int getInteger() const;
    int dfs(int depth, vector<NestedInteger>& nestedList){
        int sum = 0;
        for(auto it: nestedList){
            if(it.isInteger()){
                sum += (it.getInteger()*depth);
            }
            else{
                sum += dfs(depth+1, it.getList());
            }
        }
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(1, nestedList);
    }
};