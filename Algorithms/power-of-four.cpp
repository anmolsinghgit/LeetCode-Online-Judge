//342. Power of Four
//https ://leetcode.com/problems/power-of-four/?sort=hot
//https ://leetcode.com/discuss/97930/java-1-line-cheating-for-the-purpose-of-not-using-loops
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && !(num & (num - 1)) && (0x5555555 & num);
	}
};
int main(int argc, char** argv) {
	Solution solution;
	getchar();
	return 0;
}
