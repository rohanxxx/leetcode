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
void dfs(vector<NestedInteger> &nestedInteger, vector<int>& ans){
    for(auto& it: nestedInteger){
        if(it.isInteger()){
            ans.push_back(it.getInteger());
        }
        else{
            dfs(it.getList(), ans);
        }
    }
}
class NestedIterator {
private:
    int pos, n;
    vector<int> list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList, list);

        pos = -1;
        n = list.size();
    }
    
    int next() {
        if(hasNext()){
            pos++;
            return list[pos];
        }
        return INT_MIN;
    }
    
    bool hasNext() {
        return (pos+1 < n);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */