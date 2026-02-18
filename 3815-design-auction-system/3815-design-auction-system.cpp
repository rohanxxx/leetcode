class AuctionSystem {
public:
    unordered_map<int, multiset<pair<int,int>>> bids; 
    //bids[itemId] = Set of all bids {bidAmount, userId} for some itemId
    unordered_map<int, unordered_map<int,int>> getBid; 
    //getBid[itemId][userId] = amount that user bid or 0
    
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        int lastBid = getBid[itemId][userId];
        getBid[itemId][userId] = bidAmount; //safe to always override, we want the last one
        if(lastBid != 0){ //if there was a previous bid remove it
            bids[itemId].erase(bids[itemId].find({lastBid, userId}));
        }
        bids[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        int amount = getBid[itemId][userId];
        getBid[itemId][userId] = 0;
        bids[itemId].erase(bids[itemId].find({amount, userId}));
    }
    
    int getHighestBidder(int itemId) {
        if(bids[itemId].size() != 0){
            auto res = *bids[itemId].rbegin();
            if(res.first == 0) return -1;
            return res.second;
        }
        return -1;
    }
};