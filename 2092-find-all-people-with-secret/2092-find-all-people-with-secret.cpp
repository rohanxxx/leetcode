class Solution {
public:
    class DSU{
    public:
        vector<int> size, parent;

        DSU(int n){
            size.resize(n, 1);
            parent.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

        void reset(int node){
            parent[node] = node;
            size[node] = 1;
        }
    };

    static bool comp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), comp);

        DSU dsu(n);
        dsu.unionBySize(0, firstPerson);

        int i = 0;

        while(i < meetings.size()){
            int time = meetings[i][2];
            vector<int> nodes;

            int j = i;

            // process same-time group
            while(j < meetings.size() && meetings[j][2] == time){
                int u = meetings[j][0];
                int v = meetings[j][1];

                dsu.unionBySize(u, v);
                nodes.push_back(u);
                nodes.push_back(v);
                j++;
            }

            // 🔥 KEY FIX: invalidate people not connected to 0
            for(int x : nodes){
                if(dsu.findParent(x) != dsu.findParent(0)){
                    dsu.reset(x);
                }
            }

            i = j;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dsu.findParent(i) == dsu.findParent(0)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};