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

constexpr int MOD = 1'000'000'000;

int dp[101][10];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
        }
        dp[i][9] = dp[i - 1][8];
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << '\n';

    return 0;
}
