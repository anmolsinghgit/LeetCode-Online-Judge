// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// http://blog.csdn.net/fightforyourdream/article/details/14503469
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
	int maxProfit(const vector<int>& prices) {
		return this->maxProfit(2, prices);
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
	vector<int> prices = {1, 2, 4};
	if (solution.maxProfit(prices) == 3) {
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
	prices = {6, 1, 3, 2, 4, 7};
	if (solution.maxProfit(prices) == 7) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	prices = {3, 3, 5, 0, 0, 3, 1, 4};
	if (solution.maxProfit(prices) == 6) {
		cout << "\nPassed\n";
	} else {
		cout << "\nError\n";
		return 0;
	}
	cout << "\nPassed All\n";
	return 0;
}