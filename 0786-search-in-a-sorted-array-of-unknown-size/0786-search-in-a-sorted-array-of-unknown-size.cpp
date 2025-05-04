/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

/*
    Return the index k of the hidden array where secret[k] == target or return -1
    class ArrayReader {
        public:
            int get(int index);
    };
    ArrayReader reader();
    reader.get
*/
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == target) return 0;

        // search boundaries
        int left = 0, right = 1;
        while (reader.get(right) < target) {
            left = right;
            right = right * 2;
        }

        // binary search
        int pivot, num;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            num = reader.get(pivot);

            if (num == target) return pivot;
            if (num > target) right = pivot-1;
            else left = pivot+1;
        }

        // there is no target element
        return -1;
    }
};