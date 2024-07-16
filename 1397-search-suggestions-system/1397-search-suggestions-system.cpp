class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;

        string sw = "";

        for(auto& c: searchWord){
            sw += c;
            int len = sw.length(), count = 0;
            vector<string> v;
            for(auto& product: products){
                if(sw.substr(0, len) == product.substr(0, len)){
                    v.push_back(product);
                    count++;
                    if(count == 3) break;
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};