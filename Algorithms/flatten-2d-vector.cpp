// 251. Flatten 2D Vector
// https://leetcode.com/problems/flatten-2d-vector/
#include <iostream>
#include <vector>
using namespace std;
class Vector2D {
public:
	Vector2D(vector<vector<int>>& vec2d): x(0), y(0), n(vec2d.size()), vec2d(vec2d) {}

	int next() {
		int result = this->vec2d[this->x][this->y];
		if (this->y + 1 == this->vec2d[this->x].size()) {
			this->y = 0;
			this->x++;
			while(this->x < this->n && this->vec2d[this->x].empty()) this->x++;
			return result;
		}
		this->y++;
		return result;
	}

	bool hasNext() {
		if (this->n == 0) return false;
		while(this->x < this->n && this->vec2d[this->x].empty()) this->x++;
		if (this->x == this->n) return false;
		return true; 
	}
private:
	size_t x;
	size_t y;
	size_t n;
	vector<vector<int>> vec2d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(void) {
	vector<vector<int>> vec2d = {{1, 2}, {3}, {4, 5, 6}};
	Vector2D i(vec2d);
	while (i.hasNext()) cout << i.next() << '\t';
	cout << "\tPassed\n";
	vec2d.clear();
	while (i.hasNext()) cout << i.next() << '\t';
	cout << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}