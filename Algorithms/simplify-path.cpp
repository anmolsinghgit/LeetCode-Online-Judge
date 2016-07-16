// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
	string simplifyPath(const string& path) {
		string result("");
		if (path.empty())
			return "";
		size_t i(0);
		int slash(-1);
		vector<string> filename;
		while (i < path.size()) {
			if (path[i] == '/') {
				if (slash == -1) {
					slash = i;
					++i;
					continue;
				}
				else {
					filename.push_back(string(begin(path) + slash + 1, begin(path) + i));
					if (filename.back() == "") {
						filename.pop_back();
						slash = i;
						++i;
						continue;
					}
					else if (filename.back() == ".") {
						filename.pop_back();
						slash = i;
						++i;
						continue;						
					}
					else if (filename.back() == "..") {
						filename.pop_back();
						if (!filename.empty()) {
							filename.pop_back();
						}
						slash = i;
						++i;
						continue;						
					}
					else {
						slash = i;
						++i;
						continue;						
					}
				}
			}
			else {
				if (i == path.size() - 1) {
					filename.push_back(string(begin(path) + slash + 1, end(path)));
					if (filename.back() == "") {
						filename.pop_back();
						++i;
						continue;
					}
					else if (filename.back() == ".") {
						filename.pop_back();
						++i;
						continue;						
					}
					else if (filename.back() == "..") {
						filename.pop_back();
						if (!filename.empty()) {
							filename.pop_back();
						}
						++i;
						continue;						
					}
					else {
						++i;
						continue;						
					}					
				}
				else {
					++i;
					continue;					
				}
			}
		}
		if (filename.empty())
			return "/";
		for (const auto& i : filename) {
			result += "/" + i;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<string> a({"/home/", "/a/./b/../../c/", "/...", "/.../", "/", "/abc/..."});
	vector<string> b({"/home", "/c", "/...", "/...", "/", "/abc/..."});
	for (size_t i(0); i < b.size(); ++i) {
		cout << solution.simplifyPath(a[i]) << '\t' << b[i]; 
		if (b[i] != solution.simplifyPath(a[i])) {
			cout << "\tError\n";
			return 0;
		}
		else {
			cout << "\tPassed\n";
		}
	}
	cout << "\nPassed All\n";
	return 0;
}