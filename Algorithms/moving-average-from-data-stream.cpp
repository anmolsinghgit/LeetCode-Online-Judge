// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/
#include <iostream>
#include <deque>
#include <numeric>
using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(const int& size) {
        this->dq.clear();
        this->size = size;
    }
    
    double next(const int& val) {
        this->dq.push_front(val);
        if (this->dq.size() < this->size) 
            return double(accumulate(dq.begin(), dq.end(), 0.0)) / double(this->dq.size());
        else
            return double(accumulate(dq.begin(), dq.begin() + this->size, 0.0)) / double(this->size);
    }
private:
    deque<int> dq;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(int argc, char** argv) {
	MovingAverage m(3);
	return 0;
}
