// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/
// https://github.com/soulmachine/leetcode
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		const int n = points.size();
		if (n <= 2) return n; 
		int result = 0;
		for (int i = 0; i < n; ++i) {
			int x0 = points[i].x;
			int y0 = points[i].y;
			unordered_map<double, int> hashmap;
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				int x1 = points[j].x;
				int y1 = points[j].y;
				if (x0 == x1 && y0 == y1) {
					++sum;
					continue;
				}
				if (x0 == x1) {
					++hashmap[numeric_limits<double>::max()];
					continue;
				}
				double slope = 1.0 * (y1 - y0) / (x1 - x0);
				++hashmap[slope];
				continue;
			}
			int s = 0;
			for (const auto &e : hashmap) s = max(s, e.second);
			result = max(result, sum + s + 1);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<Point> points = {{0, 0}, {1, 1}, {1, -1}};
	if (solution.maxPoints(points) == 2) {
		cout << "\nPassed\n";
	}
	else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}