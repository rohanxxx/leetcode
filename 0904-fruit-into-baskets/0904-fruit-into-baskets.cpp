class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int left = 0, maxLen = 0;
        for(int right = 0; right < fruits.size(); right++){
            map[fruits[right]]++;
            if(left <= right && map.size() > 2){
                map[fruits[left]]--;
                if(map[fruits[left]] == 0){
                    map.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }

        return maxLen;
    }
};