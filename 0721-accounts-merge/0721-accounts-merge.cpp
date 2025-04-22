class Solution {
public:
    class DSU {
        public:
            vector<int> parent;
            vector<int> size;

            DSU(int n){
                parent.resize(n);
                size.resize(n);

                for(int i = 0; i < n; i++){
                    parent[i] = i;
                    size[i] = 1;
                }
            }

            int findParent(int node){
                if(node == parent[node]) return node;
                //it also does the path compression
                //so that next time when u try to access the ultimate parent it will take only O(1) TC
                return parent[node] = findParent(parent[node]);
            }

            void unionBySize (int node1, int node2){
                int node1parent = findParent(node1);
                int node2parent = findParent(node2);
                if(node1parent == node2parent) return;
                if(size[node1parent] < size[node2parent]){
                    parent[node1parent] = parent[node2parent];
                    size[node2parent] += size[node1parent];
                }
                else{
                    parent[node2parent] = parent[node1parent];
                    size[node1parent] += size[node2parent];
                }
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> mailMap;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                //if the email is not mapped then map it condition
                if(mailMap.find(email) == mailMap.end()){
                    //i is the node number of the graph
                    mailMap[email] = i;
                }
                else{
                    dsu.unionBySize(mailMap[email], i);
                }
            }
        }

        vector<vector<string>> merge(n);
        for(auto it: mailMap){
            int node = it.second;
            string email = it.first;

            int nodeParent = dsu.findParent(node);
            merge[nodeParent].push_back(email);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(merge[i].size() > 0){
                sort(merge[i].begin(), merge[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto email: merge[i]){
                    temp.push_back(email);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};