class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even, parity;
        while(num){
            int pop = num % 10;
            
            if(pop % 2 == 0) odd.push_back(pop);
            if(pop % 2 == 1) even.push_back(pop);
            
            parity.push_back(pop);
            num = num / 10;
        }

        reverse(parity.begin(), parity.end());
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        int ans = 0;
        for(int i = 0; i < parity.size(); i++){
            if(parity[i] % 2 == 0){
                ans = ans * 10 + odd.back();
                odd.pop_back();
            }
            else{
                ans = ans * 10 + even.back();
                even.pop_back();
            }
        }

        return ans;
    }
};