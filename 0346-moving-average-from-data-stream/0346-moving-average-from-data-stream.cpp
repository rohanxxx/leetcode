class MovingAverage {
private:
    queue<int> q;
    double sum;
    int avgSize;
public:
    MovingAverage(int size) {
        avgSize = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() <= avgSize){
            return (double)((double)sum / (double)q.size());
        }
        else{
            sum -= q.front(); q.pop();
            return (double)((double)sum / (double)avgSize);
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */