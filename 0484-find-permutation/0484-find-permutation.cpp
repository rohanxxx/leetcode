class Solution {
public:
    vector<int> findPermutation(string s) {
        stack <int> st;
        vector <int> ans;
        
        for(int i = 0; i < s.length(); i++){
            st.push(i+1);
            if(s[i] == 'I'){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        
        st.push(s.length()+1);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};