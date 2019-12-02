#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

constexpr int MAX = 2500;

short dp[MAX];  // dp[i]: number of sub-palindromes until index i
bool tested[MAX][MAX];
bool palindrome[MAX][MAX];

bool isPalindrome(const string& s, const int start, const int end) {
    if (tested[start][end]) {
        return palindrome[start][end];
    }
    tested[start][end] = true;

    if (start >= end) {
        return (palindrome[start][end] = true);
    }
    if (s[start] != s[end]) {
        return false;
    }
    return (palindrome[start][end] = isPalindrome(s, start + 1, end - 1));
}

int countPalindromes(const string& s) {
    dp[0] = 1;
    for (int right = 1; right < s.length(); right++) {
        // if whole string until `s[right]` is a palindrome
        if (isPalindrome(s, 0, right)) {
            dp[right] = 1;
            continue;
        }
        dp[right] = SHRT_MAX;
        for (int left = 1; left <= right; left++) {
            /*
             * if substring s[left]~s[right] is a palindrome,
             * then test if `dp[left - 1] + 1` is a minimum for dp[right]
             * (NEW palindrome + number of palindromes before the substring)
             */
            if (isPalindrome(s, left, right)) {
                dp[right] = min(dp[right], (short)(dp[left - 1] + 1));
            }
        }
    }
    return dp[s.length() - 1];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    cout << countPalindromes(str) << '\n';

    return 0;
}
