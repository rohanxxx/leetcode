class SparseVector {
private:
    vector<int> v;
public:
    SparseVector(vector<int> &nums) {
        //TC: O(N)
        v = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    //Overall -> TC: O(N)
    //Overall -> SC: O(N+N) = O(2N)
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        int n = vec.v.size();
        //TC: O(N)
        for(int i = 0; i < n; i++){
            ans += (v[i]*vec.v[i]);
        }
        return ans;   
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);