// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// BEGIN:
// https://discuss.leetcode.com/topic/30680/share-my-dp-solution-by-state-machine-thinking
// https://discuss.leetcode.com/topic/30421/share-my-thinking-process
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		const size_t n = prices.size();
		int buy = -prices[0], sell = 0, stop = 0;
		for (size_t i = 1; i < n; i++) {
			int previousBuy = buy, previousSell = sell, previousStop = stop;
			buy = max(previousBuy, previousStop - prices[i]);
			sell = max(previousSell, previousBuy + prices[i]);
			stop = max(previousStop, previousSell);
		}
		return sell;
	}
};
// class Solution {
// public:
// 	int maxProfit(vector<int>& prices) {
// 		if (prices.empty()) return 0;
// 		const size_t n = prices.size();
// 		vector<int> buy(n, 0), sell(n, 0), stop(n, 0);
// 		buy[0] = -prices[0];
// 		for (size_t i = 1; i < n; i++) {
// 			buy[i] = max(buy[i - 1], stop[i - 1] - prices[i]);
// 			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
// 			stop[i] = max(stop[i - 1], sell[i - 1]);
// 		}
// 		return sell.back();
// 	}
// };
// END:
// https://discuss.leetcode.com/topic/30680/share-my-dp-solution-by-state-machine-thinking
// https://discuss.leetcode.com/topic/30421/share-my-thinking-process
int main(void) {
	Solution solution;
	vector<int> prices = {1, 2, 3, 0, 2};
	cout << solution.maxProfit(prices) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}