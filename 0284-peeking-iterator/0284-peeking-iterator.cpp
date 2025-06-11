/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int it, size;
    vector<int> queue;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        queue = nums; //TC: O(N)
        size = nums.size();
        if(size > 0) it = 0;
        else it = -1;
	}
    // Returns the next element in the iteration without advancing the iterator.
    //O(1)
	int peek() {
        if(hasNext() == true) return queue[it];
        return -1;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(hasNext() == true) {
            return queue[it++];
        }
        return -1;
	}

    //O(1)
	bool hasNext() const {
        if(it > -1 && it < size) return true;
        return false;   
	}
	
};