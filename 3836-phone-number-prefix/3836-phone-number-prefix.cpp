class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        std::sort(numbers.begin(), numbers.end());
        for (size_t i{1}; i < numbers.size(); ++i) {
            if (numbers[i].starts_with(numbers[i - 1])) return false;
        }
        return true;
    }
};