class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, held = INT_MIN, reset = 0;

        for (int price : prices) {
            int preSold = sold;
            cout << "preSold: " << preSold << endl;
            sold = held + price;
            cout << "sold: " << sold << endl;
            held = max(held, reset - price);
            cout << "held: " << held << endl;
            reset = max(reset, preSold);
            cout << "reset: " << reset << endl << endl;
        }

        return max(sold, reset);
    }
};
