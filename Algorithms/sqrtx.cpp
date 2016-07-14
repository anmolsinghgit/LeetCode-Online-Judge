// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int mySqrt(const int& x) {
		if (x == 0) {
			return 0;
		}
		size_t left(1);
		size_t right(x);
		size_t mid(left + (right - left) / 2);
		while (left < right) {
			if (mid * mid == x) {
				return mid;
			}
			else if (mid * mid < x) {
				if ((mid + 1) * (mid + 1) == x) {
					return mid + 1;
				}
				else if ((mid + 1) * (mid + 1) > x) {
					return mid;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if ((mid - 1) * (mid - 1) == x) {
					return mid - 1;
				}
				else if ((mid - 1) * (mid - 1) < x) {
					return mid - 1;
				}
				else {
					right = mid - 1;
				}
			}
			mid = left + (right - left) / 2;
		}
		return mid;
	}
};
int main(void) {
	Solution solution;
	vector<int> a({2, 3, 7, 2147395599});
	vector<int> b({1, 1, 2, 46339});
	for (size_t i(0); i < b.size(); ++i) {
		if (b[i] ^ solution.mySqrt(a[i])) {
			cout << "\nError\n";
			return 0;
		}
		else {
			cout << "\nPassed\n";
		}
	}
	cout << "\nPassed All\n";
	cout << '\n';
	return 0;
}