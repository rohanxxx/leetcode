/*
    given an arr of int arr
    find the sum of min(b), where b ranges over every contiguous subarr or arr
           0,1,2,3
    arr = [3,1,2,4]
    {3} -> 3
    {3,1} -> 1
    {3 1 2} -> 1
    {3,1,2,4} -> 1
 
    {1} -> 1
    {1,2} -> 1
    {1,2,4} -> 1

    {2} -> 2
    {2,4} -> 2

    {4} -> 4
    
    3x, 1

    3 + 1 

*/
class Solution {
public:
    vector<int> findNse(vector<int>& arr){
        stack<int> stack;
        
        int n = arr.size(), i = 0;
        vector<int> temp(n, 0);
        while(i < n){
            while(!stack.empty() && arr[stack.top()] >= arr[i]){
                temp[stack.top()] = i-stack.top();
                stack.pop();
            }
            stack.push(i++);
        }
        while(!stack.empty()){
            temp[stack.top()] = i-stack.top();
            stack.pop();
        }
        return temp;
    }

    vector<int> findPse(vector<int>& arr){
        stack<int> stack;
        int i = arr.size()-1;
        vector<int> temp(i+1, 0);
        while(i >= 0){
            while(!stack.empty() && arr[stack.top()] > arr[i]){
                temp[stack.top()] = stack.top()-i;
                stack.pop();
            }
            stack.push(i--);
        }

        while(!stack.empty()){
            temp[stack.top()] = stack.top()-i;
            stack.pop();
        }
        return temp;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9+7;
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);


        int n = arr.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + ((long long)nse[i] * pse[i] % mod) * arr[i]) % mod;
        }
        return (int)sum;
    }
};