// 362. Design Hit Counter
// https://leetcode.com/problems/design-hit-counter/
// https://discuss.leetcode.com/topic/48752/simple-java-solution-with-explanation
// https://discuss.leetcode.com/topic/48758/super-easy-design-o-1-hit-o-s-gethits-no-fancy-data-structure-is-needed
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
class HitCounter {
public:
	/** Initialize your data structure here. */
	HitCounter() {}

	/** Record a hit.
		@param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		cache.push_back(timestamp);
		while (!cache.empty() && cache.front() + 300 <= timestamp) cache.pop_front();
	}

	/** Return the number of hits in the past 5 minutes.
		@param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		while (!cache.empty() && cache.front() + 300 <= timestamp) cache.pop_front();
		return cache.size();
	}
private:
	deque<int> cache;
};
// class HitCounter {
// public:
// 	/** Initialize your data structure here. */
// 	HitCounter(): times(new int[300]), hits(new int[300]) {
// 		memset(times, 0, sizeof(int) * 300);
// 		memset(hits, 0, sizeof(int) * 300);
// 	}

// 	/** Record a hit.
// 		@param timestamp - The current timestamp (in seconds granularity). */
// 	void hit(int timestamp) {
// 		int index = timestamp % 300;
// 		if (times[index] == timestamp) {
// 			++hits[index];
// 			return;
// 		}
// 		times[index] = timestamp;
// 		hits[index] = 1;
// 		return;
// 	}

// 	/** Return the number of hits in the past 5 minutes.
// 		@param timestamp - The current timestamp (in seconds granularity). */
// 	int getHits(int timestamp) {
// 		int result = 0;
// 		for (int i = 0; i < 300; ++i) if (timestamp - times[i] < 300) result += hits[i];
// 		return result;
// 	}
// private:
// 	int *times;
// 	int *hits;
// };

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
int main(void) {
	HitCounter counter;
	// hit at timestamp 1.
	counter.hit(1);

	// hit at timestamp 2.
	counter.hit(2);

	// hit at timestamp 3.
	counter.hit(3);

	// get hits at timestamp 4, should return 3.
	cout << counter.getHits(4) << "\tPassed\n";

	// hit at timestamp 300.
	counter.hit(300);

	// get hits at timestamp 300, should return 4.
	cout << counter.getHits(300) << "\tPassed\n";

	// get hits at timestamp 301, should return 3.
	cout << counter.getHits(301) << "\tPassed\n";
	cout << "\nPassed All\n";
 	return 0;
}