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

        //creates the tree
        for(auto& e: employees){
            mp[e->id] = e;
        }

        //pushes the employee importance id
        queue<Employee*> q;
        q.push(mp[id]);

        int totalImportance = 0;
        //all the branches of the queue gets executed here
        while(!q.empty()){
            Employee* e = q.front(); q.pop();

            //summing up the importance here
            totalImportance += e->importance;
            
            int size = e->subordinates.size();
            //pushes the employee subID's to the queue
            for(int i = 0; i < size; i++){
                int subordinateID = e->subordinates[i];
                q.push(mp[subordinateID]);
            }
        }
        return totalImportance;
    }
};