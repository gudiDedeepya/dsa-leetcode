class Twitter {
public:

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {tweetId, timestamp}
    unordered_map<int, vector<pair<int,int>>> tweets;

    int timer = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({tweetId, timer++});
    }

    vector<int> getNewsFeed(int userId) {

        // {timestamp, userId, index}
        priority_queue<
            tuple<int,int,int>
        > pq;

        // User's own tweets
        if (tweets.count(userId) && !tweets[userId].empty()) {

            int idx = tweets[userId].size() - 1;

            auto [tweetId, time] = tweets[userId][idx];

            pq.push({time, userId, idx});
        }

        // Tweets of people user follows
        for (int followee : following[userId]) {

            if (!tweets.count(followee))
                continue;

            if (tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;

            auto [tweetId, time] = tweets[followee][idx];

            pq.push({time, followee, idx});
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto [time, user, idx] = pq.top();
            pq.pop();

            int tweetId = tweets[user][idx].first;

            ans.push_back(tweetId);

            // Go to the previous tweet of this user
            if (idx > 0) {

                int newIdx = idx - 1;

                auto [newTweetId, newTime]
                    = tweets[user][newIdx];

                pq.push({newTime, user, newIdx});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
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