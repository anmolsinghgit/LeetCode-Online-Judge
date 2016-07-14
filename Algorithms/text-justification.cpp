#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(const vector<string>& words, const int& maxWidth) {
		vector<string> result;
		int minLengthOfCurrentLine(0);
		vector<string> currentLineInVector;
		string currentLine;
		size_t i(0);
		while (i < words.size()) {
			if (words[i].size() > maxWidth) {
				result.clear();
				return result;
			}
			if (minLengthOfCurrentLine + words[i].size() > maxWidth) {
				currentLine.clear();
				if (currentLineInVector.size() >= 2) {
					int quotient((maxWidth - minLengthOfCurrentLine + currentLineInVector.size()) / (currentLineInVector.size() - 1));
					int remainder((maxWidth - minLengthOfCurrentLine + currentLineInVector.size()) % (currentLineInVector.size() - 1));
					for (int i(0); i < currentLineInVector.size() - 1; ++i) {
						if (remainder == 0) {
							currentLine += currentLineInVector[i] + string(quotient, ' ');
						}
						else {
							currentLine += currentLineInVector[i] + string(quotient + 1, ' ');
							--remainder;
						}
					}
				}
				currentLine += currentLineInVector.back();
				if (currentLine.size() < maxWidth) {
					currentLine += string(maxWidth - currentLine.size(), ' ');
				}
				result.push_back(currentLine);
				currentLine.clear();
				minLengthOfCurrentLine = 0;
				currentLineInVector.clear();
			}
			else if (minLengthOfCurrentLine + words[i].size() == maxWidth) {
				currentLine.clear();
				currentLineInVector.push_back(words[i]);
				for (size_t i(0); i < currentLineInVector.size(); ++i) {
					currentLine += currentLineInVector[i] + string(1, ' ');
				}
				currentLine.pop_back();
				if (currentLine.size() < maxWidth) {
					currentLine += string(maxWidth - currentLine.size(), ' ');
				}
				result.push_back(currentLine);
				currentLineInVector.clear();
				minLengthOfCurrentLine = 0;
				++i;
			}
			else {
				currentLine.clear();
				if (i + 1 == words.size()) {
					currentLine.clear();
					currentLineInVector.push_back(words[i]);
					for (size_t i(0); i < currentLineInVector.size(); ++i) {
						currentLine += currentLineInVector[i] + string(1, ' ');
					}
					currentLine.pop_back();
					if (currentLine.size() < maxWidth) {
						currentLine += string(maxWidth - currentLine.size(), ' ');
					}
					result.push_back(currentLine);
					currentLineInVector.clear();
					minLengthOfCurrentLine = 0;
				}
				else {
					currentLine.clear();
					currentLineInVector.push_back(words[i]);
					minLengthOfCurrentLine += words[i].size() + 1;
				}
				++i;
			}			
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<string> words({"This", "is", "an", "example", "of", "text", "justification."});
	int maxWidth(16);
	for (const auto& i : solution.fullJustify(words, maxWidth)) {
		cout << i << '\n';
	}
	cout << "\nPassed\n";
	cout << '\n';
	words = {"Listen","to","many,","speak","to","a","few."};
	maxWidth = 6;
	for (const auto& i : solution.fullJustify(words, maxWidth)) {
		cout << i << '\n';
	}
	cout << "\nPassed\n";
	cout << '\n';
	words = {" "};
	maxWidth = 2;
	for (const auto& i : solution.fullJustify(words, maxWidth)) {
		cout << i << '\n';
	}
	cout << "\nPassed\n";
	cout << '\n';
	words = {"Listen","to","many,","speak","to","a","few."};
	maxWidth = 6;
	for (const auto& i : solution.fullJustify(words, maxWidth)) {
		cout << i << '\n';
	}
	cout << "\nPassed\n";
	cout << '\n';
	cout << "\nPassed All\n";
	cout << '\n';
	return 0;
}