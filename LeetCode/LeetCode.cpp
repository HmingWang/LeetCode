// LeetCode.cpp: 定义应用程序的入口点。
//

#include "LeetCode.h"

using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		string res;
		int b = 0, e = 0;

		for (auto i = 0; i <s.length(); ++i) {
			for (int j = i + 1; j < s.length(); ++j) {
				if ((2 * i - j + 1 >= 0) && s[j] == s[2 * i - j + 1] || (2 * i - j >= 0) && s[j] == s[2 * i - j]) {
					if (j - i >= e - b) {
						b = i;
						e = j;
					}
					continue;
				}
				else {
					break;
				}
			}
		}
		if (s[e] == s[2 * b - e]) {
			res = s.substr(2 * b - e, (e - b) * 2 + 1);
		}
		else if (s[e] == s[2 * b - e + 1]) {
			res = s.substr(2 * b - e + 1, (e - b) * 2);
		}
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("abadd") << endl;
	return 0;
}
