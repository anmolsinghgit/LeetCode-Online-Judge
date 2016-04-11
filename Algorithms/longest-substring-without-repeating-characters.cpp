class Solution {
public:
	size_t lengthOfLongestSubstring(const string& s) {
		size_t result = 0;
		size_t N = s.size();
		size_t begin = 0;
		unordered_map<char, size_t> hashMap;
		for (size_t i = 0; i < N; ++i) {
			if (hashMap.count(s[i])) {
				if (begin > hashMap[s[i]]) {
					result = max(result, i - begin + 1);
					hashMap[s[i]] = i;
				}
				else if (begin <= hashMap[s[i]]) {
					result = max(result, i - hashMap[s[i]]);
					begin = hashMap[s[i]] + 1;
					hashMap[s[i]] = i;
				}
			}
			else if (!hashMap.count(s[i])) {
				hashMap[s[i]] = i;
				result = max(result, i - begin + 1);
			}
		}
		return result;
	}
};
