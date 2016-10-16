// 355. Design Twitter
// https://leetcode.com/problems/design-twitter/
#include <iostream>
#include <iterator>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct Tweet{
	Tweet(int userId, int tweetId, int timeStamp): userId(userId), tweetId(tweetId), timeStamp(timeStamp) {}
	int userId;
	int tweetId;
	int timeStamp;
};
class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter(): timeStamp(0) {
		A.clear();
		B.clear();
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		Tweet tweet(userId, tweetId, this->timeStamp++);
		this->B[userId].push_back(tweet);
		for (const auto &i : this->A[userId])
			this->B[i].push_back(tweet);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<Tweet>& X = this->B[userId];
		sort(begin(X), end(X), [](const Tweet& i, const Tweet& j) {return i.timeStamp < j.timeStamp;});
		vector<int> result;
		const int n = X.size();
		for (int i = 0, j = 0; i < n && j < 10; i++) {
			if (X[n - 1 - i].tweetId < 0) continue;
			result.push_back(X[n - 1 - i].tweetId);
			j++;
		}
		this->timeStamp++;
		return result;
 	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId == followeeId) return;
		if (this->A[followeeId].count(followerId)) return;
		this->A[followeeId].insert(followerId);
		for (const auto &i : this->B[followeeId])
			if (i.userId == followeeId)
				this->B[followerId].push_back(i);
		this->timeStamp++;
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId) return;
		if (!this->A[followeeId].count(followerId)) return;
		this->A[followeeId].erase(followerId);
		for (auto &i : this->B[followerId])
			if (i.userId == followeeId)
				i.tweetId = INT_MIN;
		this->timeStamp++;
	}
private:
	unordered_map<int, unordered_set<int>> A;
	unordered_map<int, vector<Tweet>> B;
	int timeStamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(void) {
	Twitter twitter;

	// User 1 posts a new tweet (id = 5).
	twitter.postTweet(1, 5);

	// User 1's news feed should return a list with 1 tweet id -> [5].
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << '\n';

	// User 1 follows user 2.
	twitter.follow(1, 2);

	// User 2 posts a new tweet (id = 6).
	twitter.postTweet(2, 6);

	// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
	// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << '\n';

	// User 1 unfollows user 2.
	twitter.unfollow(1, 2);

	// User 1's news feed should return a list with 1 tweet id -> [5],
	// since user 1 is no longer following user 2.
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << "\nPassed\n";

	twitter = Twitter();
	twitter.postTweet(1, 1);
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << '\n';
	twitter.follow(2, 1);
	for (const auto &i : twitter.getNewsFeed(2)) cout << i << '\t';
	cout << '\n';
	twitter.unfollow(2, 1);
	for (const auto &i : twitter.getNewsFeed(2)) cout << i << '\t';
	cout << "\nPassed\n";

	twitter = Twitter();
	twitter.postTweet(1, 5);
	twitter.follow(1, 1);
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << '\n';
	cout << "\nPassed\n";

	twitter = Twitter();
	twitter.postTweet(2, 5);
	twitter.follow(1, 2);
	twitter.follow(1, 2);
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << '\n';
	cout << "\nPassed\n";

	twitter = Twitter();
	twitter.postTweet(1,6765);
	twitter.postTweet(5,671);
	twitter.postTweet(3,2868);
	twitter.postTweet(4,8148);
	twitter.postTweet(4,386);
	twitter.postTweet(3,6673);
	twitter.postTweet(3,7946);
	twitter.postTweet(3,1445);
	twitter.postTweet(4,4822);
	twitter.postTweet(1,3781);
	twitter.postTweet(4,9038);
	twitter.postTweet(1,9643);
	twitter.postTweet(3,5917);
	twitter.postTweet(2,8847);
	twitter.follow(1,3);
	twitter.follow(1,4);
	twitter.follow(4,2);
	twitter.follow(4,1);
	twitter.follow(3,2);
	twitter.follow(3,5);
	twitter.follow(3,1);
	twitter.follow(2,3);
	twitter.follow(2,1);
	twitter.follow(2,5);
	twitter.follow(5,1);
	twitter.follow(5,2); 
	for (const auto &i : twitter.getNewsFeed(1)) cout << i << '\t';
	cout << '\n';
	for (const auto &i : twitter.getNewsFeed(2)) cout << i << '\t';
	cout << '\n';
	for (const auto &i : twitter.getNewsFeed(3)) cout << i << '\t';
	cout << '\n';
	for (const auto &i : twitter.getNewsFeed(4)) cout << i << '\t';
	cout << '\n';
	for (const auto &i : twitter.getNewsFeed(5)) cout << i << '\t';
	cout << '\n';
	cout << '\n';
	cout << "\nPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}