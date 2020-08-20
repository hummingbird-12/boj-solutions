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

constexpr int MAX = 500;

// dp[i][j] : min multiplications required to multiply i-th to j-th matrices
int dp[MAX + 1][MAX + 1];
vector < pair < int, int > > sizes;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    sizes.resize(n + 1);

    cin >> sizes[1].first >> sizes[1].second;
    for (int i = 2; i <= n; i++) {
        cin >> sizes[i].first >> sizes[i].second;
        dp[i - 1][i] = sizes[i - 1].first * sizes[i].first * sizes[i].second;
    }

    for (int length = 2; length <= n; length++) {
        for (int from = 1; from <= n - length; from++) {
            const int to = from + length;

            dp[from][to] = INT_MAX;
            for (int mid = from; mid < to; mid++) {
                dp[from][to] = min(
                    dp[from][to],
                    dp[from][mid] + dp[mid + 1][to] +
                    sizes[from].first * sizes[mid].second * sizes[to].second
                );
            }
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}
