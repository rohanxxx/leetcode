class Solution {
public:
    /*  
                             0 1 2 3 4 5 6
        Input: groupSizes = [3,3,3,3,3,1,3]
        Output: [[5],[0,1,2],[3,4,6]]
    */
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> map;

        int n = groupSizes.size();
        for(int i = 0; i < n; i++){
            map[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto& it: map){
            int size = it.first;
            int vec_size = it.second.size();
            
            int i = 0;
            while(i < vec_size){
                vector<int> group;
                while(group.size() <= size-1){
                    group.push_back(it.second[i++]);
                }
                if(group.size()) {
                    ans.push_back(group);
                }
            }
        }

        return ans;
    }
};