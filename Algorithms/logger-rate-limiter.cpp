// 359. Logger Rate Limiter
// https://leetcode.com/problems/logger-rate-limiter/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Logger {
public:
	/** Initialize your data structure here. */
	Logger() {
		hashmap.clear();
	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
		If this method returns false, the message will not be printed.
		The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		if (!this->hashmap.count(message)) {
			this->hashmap[message] = timestamp;
			return true;
		}
		if (timestamp < (this->hashmap[message] + 10)) return false;
		this->hashmap[message] = timestamp;
		return true;		
	}
private:
	unordered_map<string, int> hashmap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

 int main(void) {
 	Logger logger;
 	cout << boolalpha << logger.shouldPrintMessage(1, "foo") << '\n';
 	cout << boolalpha << logger.shouldPrintMessage(2, "bar") << '\n';
 	cout << boolalpha << logger.shouldPrintMessage(3, "foo") << '\n';
 	cout << boolalpha << logger.shouldPrintMessage(8, "bar") << '\n';
 	cout << boolalpha << logger.shouldPrintMessage(10, "foo") << '\n';
 	cout << boolalpha << logger.shouldPrintMessage(11, "foo") << '\n';
 	cout << "\nPassed All\n";
 	return 0;
 }