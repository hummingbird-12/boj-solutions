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

#define MAX_LEN 301

using namespace std;

int dp[MAX_LEN][MAX_LEN];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        dp[1][i] = i - 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][1] = i - 1;
        for (int j = 2; j <= m; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            for (int k = 1; k <= i / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k <= j / 2; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
