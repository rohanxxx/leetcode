class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        for(int i = 2; i < colors.size(); i++){
            if(colors[i] != colors[i-1] && colors[i-1] != colors[i-2]){
                count++;
            }
        }
        if(colors.back() != colors[0] && colors[0] != colors[1]){
            count++;
        }
        if(colors[colors.size()-2] != colors.back() && colors.back() != colors[0]){
            count++;
        }
        return count;
    }
};