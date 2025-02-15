class Solution {
public:
    string getBinaryString(bitset<16>& bits){
        string s = bits.to_string();
        int index = s.find('1');
        return s.substr(index);
    }
    string convertDateToBinary(string date) {
        bitset<16> year(stoi(date.substr(0, 4)));
        bitset<16> month(stoi(date.substr(5, 2)));
        bitset<16> day(stoi(date.substr(8, 2)));

        string ans = "";
        ans += getBinaryString(year);
        ans += '-';
        ans += getBinaryString(month);
        ans += '-';
        ans += getBinaryString(day);

        return ans;
    }
};