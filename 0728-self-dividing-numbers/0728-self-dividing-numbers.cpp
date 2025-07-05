class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        //SC: O(N)
        vector<int> ans;
        //TC:O(N*LogI)
        for(int i = left; i <= right; i++){
            int num = i;
            bool check = true;
            //TC: O(LogI)
            while(num){
                int pop = num % 10;
                if(pop == 0 || i % pop != 0){
                    check = false;
                    break;
                }

                num = num/10;
            }
            if(check == true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};