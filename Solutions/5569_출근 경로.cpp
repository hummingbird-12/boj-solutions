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

constexpr int MOD = 100'000;

/*
 * dp[i][j][0] : Ways to reach (i,j) with rightwards move
 * dp[i][j][1] : Ways to reach (i,j) with upwards move
 */
int dp[101][101][2];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;

    for (int i = 1; i <= w; i++) {
        dp[i][1][0] = 1;
    }

    for (int i = 1; i <= h; i++) {
        dp[1][i][1] = 1;
    }

    for (int i = 2; i <= w; i++) {
        for (int j = 2; j <= h; j++) {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j - 1][1]) % MOD;
            dp[i][j][1] = (dp[i][j - 1][1] + dp[i - 1][j - 1][0]) % MOD;
        }
    }
    cout << (dp[w][h][0] + dp[w][h][1]) % MOD << '\n';

    return 0;
}
