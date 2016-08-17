// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/
// https://discuss.leetcode.com/topic/8487/i-did-it-in-10-lines-of-c
// https://discuss.leetcode.com/topic/8894/clean-java-solution-hashmap-bits-manipulation
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		if (s.size() <= 10) return result;
		unordered_map<string, int> hashMap;
		for (size_t i = 0; i + 10 <= s.size(); ++i) ++hashMap[s.substr(i, 10)];
		for (const auto &i : hashMap) if (i.second >= 2) result.push_back(i.first);
		return result;
	}
};
int main(void) {
	Solution solution;
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	for (const auto &i : solution.findRepeatedDnaSequences(s))
		cout << i << '\t';
	cout << "\tPassed\n";
	s = "AAAAAAAAAAA";
	for (const auto &i : solution.findRepeatedDnaSequences(s))
		cout << i << '\t';
	cout << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}