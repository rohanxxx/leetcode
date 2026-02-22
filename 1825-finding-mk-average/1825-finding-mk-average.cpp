#include <bits/stdc++.h>
using namespace std;

class MKAverage {
private:
    int k, m;
    long long sum, minSum, maxSum;

    deque<int> v;                 // keep name v, but must be deque for pop_front
    multiset<int> minHeap;        // k smallest
    multiset<int> midHeap;        // middle (m - 2k)
    multiset<int> maxHeap;        // k largest

    void rebalance() {
        // Fix sizes: minHeap size == k
        while ((int)minHeap.size() > k) {
            multiset<int>::iterator it = prev(minHeap.end()); // largest in minHeap
            int x = *it;
            minHeap.erase(it);
            minSum -= x;

            midHeap.insert(x);
        }
        while ((int)minHeap.size() < k && !midHeap.empty()) {
            multiset<int>::iterator it = midHeap.begin();     // smallest in midHeap
            int x = *it;
            midHeap.erase(it);

            minHeap.insert(x);
            minSum += x;
        }

        // Fix sizes: maxHeap size == k
        while ((int)maxHeap.size() > k) {
            multiset<int>::iterator it = maxHeap.begin();     // smallest in maxHeap
            int x = *it;
            maxHeap.erase(it);
            maxSum -= x;

            midHeap.insert(x);
        }
        while ((int)maxHeap.size() < k && !midHeap.empty()) {
            multiset<int>::iterator it = prev(midHeap.end()); // largest in midHeap
            int x = *it;
            midHeap.erase(it);

            maxHeap.insert(x);
            maxSum += x;
        }

        // Fix ordering: all minHeap <= midHeap <= maxHeap
        while (!minHeap.empty() && !midHeap.empty()) {
            int a = *prev(minHeap.end()); // largest in minHeap
            int b = *midHeap.begin();     // smallest in midHeap
            if (a <= b) break;

            // swap a and b
            minHeap.erase(prev(minHeap.end()));
            midHeap.erase(midHeap.begin());

            minHeap.insert(b);
            midHeap.insert(a);

            minSum += (long long)b - a;
        }

        while (!midHeap.empty() && !maxHeap.empty()) {
            int a = *prev(midHeap.end()); // largest in midHeap
            int b = *maxHeap.begin();     // smallest in maxHeap
            if (a <= b) break;

            // swap a and b
            midHeap.erase(prev(midHeap.end()));
            maxHeap.erase(maxHeap.begin());

            midHeap.insert(b);
            maxHeap.insert(a);

            maxSum += (long long)a - b;
        }
    }

    void eraseOne(multiset<int>& ms, int x) {
        multiset<int>::iterator it = ms.find(x);
        if (it != ms.end()) ms.erase(it);
    }

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        sum = minSum = maxSum = 0;
    }

    void addElement(int num) {
        v.push_back(num);
        sum += num;

        // insert into one of the buckets (roughly)
        if (!minHeap.empty() && num <= *prev(minHeap.end())) {
            minHeap.insert(num);
            minSum += num;
        } else if (!maxHeap.empty() && num >= *maxHeap.begin()) {
            maxHeap.insert(num);
            maxSum += num;
        } else {
            midHeap.insert(num);
        }

        // if window too big, remove oldest
        if ((int)v.size() > m) {
            int delElement = v.front();
            v.pop_front();
            sum -= delElement;

            // remove from whichever set contains it
            multiset<int>::iterator it;

            it = minHeap.find(delElement);
            if (it != minHeap.end()) {
                minHeap.erase(it);
                minSum -= delElement;
            } else {
                it = maxHeap.find(delElement);
                if (it != maxHeap.end()) {
                    maxHeap.erase(it);
                    maxSum -= delElement;
                } else {
                    eraseOne(midHeap, delElement);
                }
            }
        }

        rebalance();
    }

    int calculateMKAverage() {
        if ((int)v.size() < m) return -1;

        int denom = m - 2 * k;
        if (denom <= 0) return 0;

        long long middleSum = sum - minSum - maxSum;
        return (int)(middleSum / denom);
    }
};