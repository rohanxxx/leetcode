class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxDamage = 0;
        long long sum = 0;
        for(auto& d: damage){
            sum += d;
            maxDamage = max(maxDamage, d);
        }

        return sum-(int)min(armor, maxDamage)+1;
    }
};