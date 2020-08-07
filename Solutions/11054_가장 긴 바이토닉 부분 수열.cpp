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

constexpr int MAX = 1000;

/*
 * dp[0][i] : length of LIS ending in i-th number
 * dp[1][i] : length of LIS ending in i-th number of the reversed sequence
 */
short dp[2][MAX];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector < short > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dp[0][0] = dp[1][n - 1] = 1;
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[1][n - 1 - i] = 1;
        for (int j = 0; j < i; j++) {
            // Update length of LIS
            if (v[j] < v[i]) {
                dp[0][i] = max(dp[0][i], (short)(dp[0][j] + 1));
            }
            // Update length of LIS of reversed sequence
            if (v[n - 1 - j] < v[n - 1 - i]) {
                dp[1][n - 1 - i] = max(dp[1][n - 1 - i], (short)(dp[1][n - 1 - j] + 1));
            }
        }
    }

    // Maximum of sum of lengths of LIST of in-order and reversed sequences
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    }

    cout << ans << '\n';

    return 0;
}
