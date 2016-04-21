//231. Power of Two
//https://leetcode.com/problems/power-of-two/
//http://www.cnblogs.com/grandyang/p/4623394.html
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && !(n & (n - 1));
	}
};
int main(int argc, char** argv) {
	Solution solution;
	cout << "Passed!\n";
	getchar();
	return 0;
}
