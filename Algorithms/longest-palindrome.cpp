// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestPalindrome(string s) {
		int hashMap[52];
		memset(hashMap, 0, sizeof(hashMap));
		for (const auto&i : s) {
			if (i >= 'a') hashMap[i - 'a']++;
			else hashMap[i - 'A' + 26]++;
		}
		int result = 0, hasOdd = 0;
		for (int i = 0; i < 52; i++) {
			if (hashMap[i] == 0) continue;
			if ((hashMap[i] & 1) == 0)  result += hashMap[i];
			else {
				result += hashMap[i] - 1;
				hasOdd = 1;
			}
		}
		return result + hasOdd;
	}
};
int main(void) {
	Solution solution;
	cout << solution.longestPalindrome("abccccdd") << "\tPassed\n";
	cout << solution.longestPalindrome("AAAAAA") << "\tPassed\n";
	cout << solution.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}