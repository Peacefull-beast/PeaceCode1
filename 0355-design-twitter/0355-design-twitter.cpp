#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Twitter {
public:
    // Each user has a list of tweets, each with a unique ID and timestamp
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> {tweetId, timestamp}
    unordered_map<int, unordered_set<int>> followers;  // userId -> set of followers
    int timestamp; // Global timestamp to keep tweets in order
    
    Twitter() : timestamp(0) {}

    // Add a new tweet by a user
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp++);
    }
    
    // Retrieve the 10 most recent tweets in the user's feed
    vector<int> getNewsFeed(int userId) {
        // Min-heap to keep track of the top 10 tweets based on timestamp
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        // Check user's own tweets
        for (auto& tweet : tweets[userId]) {
            pq.push({tweet.second, tweet.first});
            if (pq.size() > 10) pq.pop();
        }
        
        // Check tweets of each followed user
        for (int followeeId : followers[userId]) {
            if (followeeId == userId) continue;
            for (auto& tweet : tweets[followeeId]) {
                pq.push({tweet.second, tweet.first});
                if (pq.size() > 10) pq.pop();
            }
        }
        
        
        vector<int> feed;
        while (!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    // Follow another user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    // Unfollow a user
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
