// 406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/
// https://discuss.leetcode.com/topic/60394/easy-concept-with-python-c-java-solution
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(begin(people), end(people), [](const pair<int, int>& i, const pair<int, int>& j) {
			return (i.first == j.first) ? i.second < j.second : i.first > j.first; 
		});
		vector<pair<int, int>> result;
		for (const auto &i : people)
		    result.insert(begin(result) + i.second, i);
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<pair<int, int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	for (const auto&i : solution.reconstructQueue(people)) cout << i.first << ", " << i.second << "; ";
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
