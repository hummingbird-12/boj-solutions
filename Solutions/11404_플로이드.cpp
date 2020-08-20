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

constexpr int INF = 999'999'999;

int dp[101][101];

void floyd_warshall(const int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(dp[i] + 1, dp[i] + n + 1, INF);
        dp[i][i] = 0;
    }

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
    }

    floyd_warshall(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (dp[i][j] != INF ? dp[i][j] : 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
