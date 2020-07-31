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

constexpr int MOD = 10'007;
short dp[1001][10]; // dp[i][j] : count of numbers of length `i` ending in digit `j`

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= MOD;
            }
        }
    }

    short cnt = 0;
    for (int i = 0; i < 10; i++) {
        cnt += dp[n][i];
        cnt %= MOD;
    }
    cout << cnt << '\n';

    return 0;
}
