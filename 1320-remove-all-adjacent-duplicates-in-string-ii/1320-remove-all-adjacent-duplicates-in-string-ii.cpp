class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;
        for(char c: s){
            if(!stack.empty()){
                pair<char, int> p = stack.top();
                if(p.first == c && p.second+1 == k){
                    stack.pop();
                    continue;
                }
                if(p.first == c){
                    stack.pop();
                    stack.push({p.first, p.second+1});
                    continue;
                }
            }
            stack.push({c, 1});
        }
        string ans = "";
        while(!stack.empty()){
            pair<char, int> p = stack.top(); stack.pop();
            for(int i = 0; i < (int)p.second; i++){
                ans += (char)p.first;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};