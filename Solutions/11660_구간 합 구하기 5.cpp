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

constexpr int MAX = 1025;

int dp[MAX][MAX]; // dp[i][j] : sum from (1,1) to (i,j)

inline int query(const int x1, const int y1, const int x2, const int y2) {
    int ans = dp[x2][y2];
    ans -= dp[x1 - 1][y2];
    ans -= dp[x2][y1 - 1];
    ans += dp[x1 - 1][y1 - 1];

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, num;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + num;
        }
    }

    int x1, y1, x2, y2;
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << '\n';
    }

    return 0;
}
