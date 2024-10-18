class Logger {
public:
    Logger() {
        
    }
    map<string, int> ok;
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message])
            return false;
        ok[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */