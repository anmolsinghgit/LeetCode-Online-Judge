// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// https://discuss.leetcode.com/topic/726/is-this-question-a-joke
// http://blog.unieagle.net/2012/12/04/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Abest-time-to-buy-and-sell-stock-ii/
// https://discuss.leetcode.com/topic/52580/java-solution-in-o-n-time-and-o-k-space/2
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
	int maxProfit(const vector<int>& prices) {
		return this->maxProfit(prices.size(), prices);
	}
private:
	int maxProfit(const size_t& k, const vector<int>& prices) {
		if (prices.empty()) return 0;
		if (k >= prices.size() / 2) {
			int result = 0;
			for (size_t i = 1; i < prices.size(); ++i) result += max(0, prices[i] - prices[i - 1]);
			return result;
		}
		vector<int> buy(k + 1, INT_MIN);
		vector<int> sell(k + 1, 0);
		for (const auto& price : prices) {
			for (size_t i = 1; i < k + 1; ++i) {
				buy[i] = max(buy[i], sell[i - 1] - price);
				sell[i] = max(sell[i], buy[i] + price);
			}
		}
		return sell[k];
	}
};
int main(void) {
	Solution solution;
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	if (solution.maxProfit(prices) == 7) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	prices = {7, 6, 4, 3, 1};
	if (solution.maxProfit(prices) == 0) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}