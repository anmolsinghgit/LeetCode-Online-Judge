// 134. Gas Station
// https://leetcode.com/problems/gas-station/
// https://github.com/soulmachine/leetcode
// http://bangbingsyb.blogspot.ca/2014/11/leetcode-gas-station.html
// https://discuss.leetcode.com/topic/1344/share-some-of-my-ideas/2
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
		int tank = 0, result = 0, sum = 0;
		for (size_t i = 0; i < gas.size(); ++i) {
			tank += gas[i] - cost[i];
			sum	+= gas[i] - cost[i];
			if (gas[i] < cost[i]) {
				result = i + 1;
				tank = 0;
			}
		}
		return sum >= 0 ? result : -1;
	}
};
int main(void) {
	Solution solution;
	vector<int> gas = {4};
	vector<int> cost = {5};
	if (solution.canCompleteCircuit(gas, cost) == -1) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}