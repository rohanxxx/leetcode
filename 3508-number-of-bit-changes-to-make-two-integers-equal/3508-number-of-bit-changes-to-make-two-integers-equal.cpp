class Solution {
public:
    int minChanges(int n, int k) {
        bitset<32> nint(n);
        bitset<32> kint(k);

        string nString = nint.to_string();
        string kString = kint.to_string();

        int nIndex = nString.find('1');
        int kIndex = kString.find('1');

        int index = min(nIndex, kIndex);

        int count = 0;
        for(int i = index; i < 32; i++){
            if(nString[i] == '1' && kString[i] == '0'){
                nString[i] = '0';
                count++;
            }
        }

        if(nString != kString){
            return -1;
        }
        return count;
    }
};