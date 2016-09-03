// 320. Generalized Abbreviation
// https://leetcode.com/problems/generalized-abbreviation/
// https://discuss.leetcode.com/topic/32270/java-backtracking-solution
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> result;
		this->backTracking(result, word, 0, "", 0);
		return result;
	}
private:
	void backTracking(vector<string>& result, string& word, size_t position, string current, int count) {
		if (position == word.size()) {
			if (count > 0) current += to_string(count);
			result.push_back(current);
			return;
		}
		this->backTracking(result, word, position + 1, current, count + 1);
		this->backTracking(result, word, position + 1, current + (count > 0 ? to_string(count) : "") + word[position], 0);
	}
};
int main(void) {
	Solution solution;
	string word = "word";
	for (const auto &i : solution.generateAbbreviations(word)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}