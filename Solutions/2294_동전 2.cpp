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

int dp[100][10'001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector < int > coins(n);
    cin >> coins[0];
    for (int i = 1; i <= k; i++) {
        dp[0][i] = -1;
    }
    for (int i = coins[0]; i <= k; i += coins[0]) {
        dp[0][i] = i / coins[0];
    }

    for (int i = 1; i < n; i++) {
        cin >> coins[i];
        dp[i][1] = (coins[i] == 1 ? 1 : dp[i - 1][1]);
        for (int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            for (int c = coins[i]; c <= j; c += coins[i]) {
                if (dp[i - 1][j - c] != -1) {
                    dp[i][j] = min(dp[i][j], c / coins[i] + dp[i - 1][j - c]);
                }
            }
            if (dp[i - 1][j] != -1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            if (dp[i][j] == INT_MAX) {
                dp[i][j] = -1;
            }
        }
    }
    cout << dp[n - 1][k] << '\n';

    return 0;
}
