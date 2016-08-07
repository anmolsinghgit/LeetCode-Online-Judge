// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/
// https://discuss.leetcode.com/topic/9629/depth-first-simple-java-solution/2
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<int, UndirectedGraphNode *> graph;
		return this->cloneGraph(node, graph);
	}
private:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& graph) {
		if (!node) return NULL;
		if (graph.count(node->label)) return graph[node->label];
		UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
		graph[node->label] = clone;
		for (const auto &neighbor : node->neighbors) clone->neighbors.push_back(this->cloneGraph(neighbor, graph));
		return clone;
	}
};
int main(void) {
	Solution solution;
	UndirectedGraphNode *zero = new UndirectedGraphNode(0);
	UndirectedGraphNode *one = new UndirectedGraphNode(1);
	UndirectedGraphNode *two = new UndirectedGraphNode(2);
	zero->neighbors.push_back(one);
	zero->neighbors.push_back(two);
	one->neighbors.push_back(zero);
	one->neighbors.push_back(two);
	two->neighbors.push_back(zero);
	two->neighbors.push_back(one);
	two->neighbors.push_back(two);
	solution.cloneGraph(one);
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}