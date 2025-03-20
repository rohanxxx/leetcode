/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(auto e: employees){
            mp[e->id] = e;
        }

        queue<Employee*> q; q.push(mp[id]);

        int totalImportance = 0;
        while(!q.empty()){
            Employee* e = q.front(); q.pop();
            totalImportance += e->importance;
            
            int size = e->subordinates.size();
            for(int i = 0; i < size; i++){
                int subOrdinateId = e->subordinates[i];
                q.push(mp[subOrdinateId]);
            }
        }
        return totalImportance;
    }
};