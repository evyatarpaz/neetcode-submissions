class Twitter {
private:
    std::unordered_map<int, std::vector<pair<int,int>>> _tweetMap;
    std::unordered_map<int, std::unordered_set<int>> _followMap;
    int _count;
public:
    Twitter() {
        _count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        _tweetMap[userId].emplace_back(_count++,tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<pair<int,int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> min_heap;

        auto add_to_heap = [&min_heap](const std::pair<int,int>& tweet_pair){
            min_heap.emplace(tweet_pair);
            if(min_heap.size() > 10){
                min_heap.pop();
            }
        };
        if(_tweetMap.find(userId) != _tweetMap.end()){
            for(const auto& tweet_pair : _tweetMap[userId]){
                add_to_heap(tweet_pair);
            }
        }
        if(_followMap.find(userId) != _followMap.end()){
            for(const int follow : _followMap[userId]){
                if(_tweetMap.find(follow) != _tweetMap.end()){
                    for(const auto& tweet_pair : _tweetMap[follow]){
                        add_to_heap(tweet_pair);
                    }
                }
            }
        }
        
        std::vector<int> res;
        while(!min_heap.empty()){
            res.emplace_back(min_heap.top().second);
            min_heap.pop();
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        _followMap[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        _followMap[followerId].erase(followeeId);
    }
};
