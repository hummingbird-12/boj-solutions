#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int MOD = 1000000;
constexpr int MAX_LEN = 5001;
constexpr int MIN_CODE = 1;
constexpr int MAX_CODE = 26;

constexpr int SINGLE_DIGIT = 0;
constexpr int DOUBLE_DIGIT = 1;
int dp[MAX_LEN][2] = { { 1 } };

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string code;
    cin >> code;

    if (code.at(0) == '0') {
        cout << 0 << '\n';
        return 0;
    }

    int current, lastTwo;
    int len = code.length();

    for (int i = 1; i < len; i++) {
        current = code.at(i) - '0';
        lastTwo = stoi(code.substr(i - 1, 2));

        if (current != 0) {
            dp[i][SINGLE_DIGIT] = (dp[i - 1][SINGLE_DIGIT] + dp[i - 1][DOUBLE_DIGIT]) % MOD;
        }

        if (lastTwo >= MIN_CODE && lastTwo <= MAX_CODE) {
            dp[i][DOUBLE_DIGIT] = dp[i - 1][SINGLE_DIGIT];
        }
    }

    cout << (dp[len - 1][SINGLE_DIGIT] + dp[len - 1][DOUBLE_DIGIT]) % MOD << '\n';

    return 0;
}
