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

int dp[1001][31]; // dp[i][j] : max number of plumes at i-th iteration when moved j times

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, w;
    cin >> t >> w;

    int a;
    cin >> a;
    (a == 1 ? dp[1][0] : dp[1][1]) = 1;

    for (int i = 2; i <= t; i++) {
        cin >> a;
        dp[i][0] = dp[i - 1][0] + (a == 1); // stayed on tree #1
        for (int j = 1; j <= w; j++) {
            /*
             * Either just made the j-th move from the (i - 1)th iteration
             * or stayed on same tree after making the j moves until (i - 1)th iteration.
             * Plume count increases when `(a % 2 != j % 2)`
             */
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + (a % 2 != j % 2);
        }
    }

    int ans = dp[t][0];
    for (int i = 1; i <= w; i++) {
        ans = max(ans, dp[t][i]);
    }
    cout << ans << '\n';

    return 0;
}
