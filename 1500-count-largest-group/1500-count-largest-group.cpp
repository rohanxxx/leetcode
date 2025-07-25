class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> map(n+1, 0);

        int maxSize = 0;
        //O(N*LogK)
        for(int i = 1; i <= n; i++){
            int sum = 0;
            int num = i;
            while(num){
                sum += (num % 10);
                num /= 10;
            }
            maxSize = max(maxSize, ++map[sum]);
        }

        int count = 0;
        for(int i = 1; i <= n; i++){
            if(map[i] == maxSize) count++;
        }

        return count;
    }
};