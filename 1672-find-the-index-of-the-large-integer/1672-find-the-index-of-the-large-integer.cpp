/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
         int left = 0;
        int length = reader.length();
        
        while (length > 1) {
            length /= 2;
            // The left subarray starts from index left, and the right subarray starts from left + length
            // Both subarrays have 'length' elements
            int cmp = reader.compareSub(left, left + length - 1, left + length, left + 2 * length - 1);
            cout << "cmp: " << cmp << endl;
            
            if (cmp == 0) {
                // The extra element is the larger integer
                return left + 2 * length;
            }
            
            if (cmp < 0) {
                left += length;
            }
        }
        
        return left;
    }
};