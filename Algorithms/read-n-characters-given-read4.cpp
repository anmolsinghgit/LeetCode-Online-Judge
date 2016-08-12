// 157. Read N Characters Given Read4
// https://leetcode.com/problems/read-n-characters-given-read4/
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
		int k = n / 4;
		int b = n % 4;
		int c = 4;
		int result = 0;
		for (int i = 0; i < k; ++i) {
			int r = read4(buf + c * i);
			result += r;
			if (r < c) return result;
		}
		if (b == 0) return result;
		char *remain = new char[c];
		int r = read4(remain);
		for (int i = 0; i < r && i < b; ++i) buf[k * c + i] = remain[i];
		return result + min(r, b);
	}
};