/*
           0 1 2 3 4 5 6
    arr = [4,2,3,0,3,1,2], start = 5
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);

        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(arr[node] == 0){
                return true;
            }

            int adjfront = node - arr[node];
            int adjback = node + arr[node];

            if(adjfront >= 0 && adjfront < n && visited[adjfront] == 0){
                q.push(adjfront);
                visited[adjfront] = 1;
            }

            if(adjback >= 0 && adjback < n && visited[adjback] == 0){
                q.push(adjback);
                visited[adjback] = 1;
            }
        }

        return false;
    }
};