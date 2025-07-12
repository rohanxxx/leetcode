/*
    ["034","329","318","31"]
    
    034, 31, 318, 329
*/
class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        sort(numbers.begin(), numbers.end());
        /*for(auto& it: numbers){
            cout << it << " ";
        }
        cout << endl;*/
        int n = numbers.size();
        for(int i = 1; i < n; i++){
            string prefix = numbers[i].substr(0, numbers[i-1].size());
            if(numbers[i-1] == prefix) return false;
        }
        return true;
    }
};