class ZigzagIterator {
private: 
    int ptr;
    int size;
    vector<int> v;
public:
    //TC: O(N+M)
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        ptr = 0;
        int stop = min((int)v1.size(), (int)v2.size());
        int maxStop = max((int)v1.size(), (int)v2.size());
        for(int i = 0; i < stop; i++){
            v.push_back(v1[i]);
            v.push_back(v2[i]);
        }
        for(int i = stop; i < maxStop; i++){
            if((int)v1.size() > stop) v.push_back(v1[i]);
            if((int)v2.size() > stop) v.push_back(v2[i]);
        }
        size = v.size();
    }

    //TC: O(1)
    int next() {
        if(ptr < size){
            return v[ptr++];
        }
        return -1;
    }

    //TC: O(1)
    bool hasNext() {
        if(ptr < size) return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */