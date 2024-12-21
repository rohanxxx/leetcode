class Allocator {
public:
    vector<int> memory;
    Allocator(int n) {
        memory.resize(n);
    }
    
    int allocate(int size, int mID) {
        int count = 0;
        int free = 0;
        
        for(int i = 0; i < memory.size(); i++){
            if(memory[i] == free) count++;
            else count = 0;

            if(count == size){
                while(count){
                    memory[i-count+1] = mID;
                    count--;
                }
                return i-size+1;
            }
        }

        return -1;
    }
    
    int freeMemory(int mID) {
        int count = 0;
        for(int i = 0; i < memory.size(); i++){
            if(memory[i] == mID) {
                memory[i] = 0;
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */