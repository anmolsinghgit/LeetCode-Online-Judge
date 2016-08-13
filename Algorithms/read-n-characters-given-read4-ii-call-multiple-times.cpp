// 158. Read N Characters Given Read4 II - Call multiple times
// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// https://discuss.leetcode.com/topic/7094/a-simple-java-code/4
// http://www.cnblogs.com/EdwardLiu/p/4240616.html
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
	/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
	int read(char *buf, int n) {
		int result = 0;
		while (result < n) {
			if (cachePtr == 0) cacheCnt = read4(cache);
			if (cacheCnt == 0) break;
			while (result < n && cachePtr < cacheCnt) buf[result++] = cache[cachePtr++];
			if (cachePtr >= cacheCnt) cachePtr = 0;
		}
		return result;
	}
private:
	char *cache = new char[4];
	int cacheCnt = 0;
	int cachePtr = 0;
};

// "ab"
// [read(1),read(2)]