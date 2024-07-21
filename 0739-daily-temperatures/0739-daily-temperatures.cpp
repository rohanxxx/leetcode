class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<vector<int>>stack;
        vector<int> ans(t.size(), 0);
        for(int i = t.size()-1; i >= 0; i--){
            if(stack.empty()) stack.push({t[i], i});
            else{
                int stackSize = stack.size();
                for(int j = 0; j < stackSize; j++){
                    vector<int> v = stack.top();
                    if(t[i] < v[0]){
                        ans[i] = v[1]-i;
                        stack.push({t[i], i});
                        break;
                    }
                    else{
                        stack.pop();
                        if(stack.empty()){
                            stack.push({t[i], i});
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};