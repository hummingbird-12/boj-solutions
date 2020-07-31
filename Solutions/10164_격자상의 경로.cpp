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

int dp[16][16];

void preprocess() {
    for (int i = 1; i <= 15; i++) {
        dp[1][i] = dp[i][1] = 1;
    }

    for (int i = 2; i <= 15; i++) {
        for (int j = 2; j <= 15; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    preprocess();

    int n, m, k;
    cin >> n >> m >> k;

    int x = (k != 0 ? (((k - 1) / m) + 1) : n);
    int y = (k != 0 ? (((k - 1) % m) + 1) : m);
    cout << dp[x][y] * dp[n - x + 1][m - y + 1] << '\n';

    return 0;
}
