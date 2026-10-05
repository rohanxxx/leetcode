class Solution {
public:
    void dfs1(string& region, unordered_map<string, string>& parent, unordered_map<string, bool>& visited){
        visited[region] = true;
        //if not found then return nothing
        if(parent.find(region) == parent.end()){
            return;
        }
        string p = parent[region];

        if(visited[p] == false){
            dfs1(p, parent, visited);
        }
        return;
    }
    string dfs2(string& region, unordered_map<string, string>& parent, unordered_map<string, bool>& visited){
        //visited[region] = true;
        //if already visited by dfs1 then this is the first shared ancestor
        if(visited[region] == true){
            return region;
        }
        visited[region] = true;
        //if not found then return empty string
        if(parent.find(region) == parent.end()){
            return "";
        }
        
        return dfs2(parent[region], parent, visited);
    }
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        //string root = "";
        //generate the graph's parent
        for(auto region: regions){
            int n = region.size();
            string parent_region = region[0];
            for(int i = 1; i < n; i++){
                parent[region[i]] = parent_region;
            }
        }

        unordered_map<string, bool> visited;
    
        dfs1(region1, parent, visited);
        return dfs2(region2, parent, visited);
    }
};