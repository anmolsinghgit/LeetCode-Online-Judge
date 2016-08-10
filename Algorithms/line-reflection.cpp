// 356. Line Reflection
// https://leetcode.com/problems/line-reflection/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isReflected(vector<pair<int, int>>& points) {
		unordered_map<int, unordered_set<int>> hashmap;
		int counter = 0;
		int xmin = INT_MAX;
		int xmax = INT_MIN;
		for (const auto &point : points) {
			xmin = min(xmin, point.first);
			xmax = max(xmax, point.first);
		}
		int checksum = xmin + xmax;
		for (const auto &point : points) {
			if (2 * point.first == checksum) continue;
			if (hashmap.count(point.second) && hashmap[point.second].count(point.first)) continue;
			if (hashmap.count(point.second) && hashmap[point.second].count(checksum - point.first)) {
				hashmap[point.second].insert(point.first);
				--counter;
				continue;
			}
			hashmap[point.second].insert(point.first);
			++counter;
			continue;			
		}
		return counter == 0;
	}
};
int main(void) {
	Solution solution;
	vector<pair<int, int>> points = {{1, 1}, {-1, 1}};
	if (solution.isReflected(points)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	points = {{1, 1}, {-1, -1}};
	if (!solution.isReflected(points)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	points = {{-16, 1}, {16, 1}, {16, 1}};
	if (solution.isReflected(points)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	points = {{0, 0}};
	if (solution.isReflected(points)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	points = {{0, 0}, {1, 0}};
	if (solution.isReflected(points)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	points = {{0, 0}, {1, 0}, {3, 0}};
	if (!solution.isReflected(points)) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}