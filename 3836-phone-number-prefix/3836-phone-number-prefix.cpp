class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        int n = numbers.size();

        //TC: O(N*N*m)
        //SC: O(1)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string prefix = "";
                if(numbers[i].size() <= numbers[j].size()){
                    prefix = numbers[j].substr(0, numbers[i].size());
                    if(numbers[i] == prefix){
                        return false;
                    }
                }
                else{
                    prefix = numbers[i].substr(0, numbers[j].size());
                    if(numbers[j] == prefix){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};