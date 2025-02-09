class Solution {
public:
    int compress(vector<char>& chars) {
        int i, j, count = 0;
        for(i = 0, j = 0; i < chars.size(); i++){
            if(chars[j] == chars[i]){
                count++;
            }
            else{
                if(count == 1){
                    chars[++j] = chars[i];
                    continue;
                }
                if(count < 10){
                    chars[++j] = '0'+count;
                    chars[++j] = chars[i];
                    count = 1;
                    continue;
                }
                string str_count = to_string(count);
                for(int k = 0; k < str_count.length(); k++){
                    chars[++j] = '0'+(int)(str_count[k]-'0');
                }
                chars[++j] = chars[i];
                count = 1;
            }
        }
        /*
        cout << "count: " << count << endl;
        cout << "j: " << j << endl;
        cout << "chars[j]: " << chars[j] << endl;
        */
        if(count > 1){
            if(count < 10){
                chars[++j] = '0'+count;
            }
            else{
                string str_count = to_string(count);
                // cout << "str_count: " << str_count << endl;
                for(int k = 0; k < str_count.length(); k++){
                    // cout << "0 + str_count[k]: " << static_cast<char>('0'+ (int)(str_count[k] - '0')) << endl;
                    chars[++j] = '0'+(int)(str_count[k]-'0');
                    // cout << "chars[" << j << "]: " << chars[j] << endl;
                }
            }
        }
        return j+1;
    }
};