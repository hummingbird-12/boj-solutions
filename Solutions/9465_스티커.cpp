#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tc;

    vector < vector < int > > sticker;
    vector < vector < int > > dp;

    scanf("%d", &tc);

    while (tc--) {
        int n, a;

        scanf("%d", &n);
        sticker.resize(3);
        dp.resize(3);
        for (int i = 0; i <= 2; i++) {
            sticker[i].resize(n + 1);
            dp[i].resize(n + 1);
            if (i) {
                for (int j = 1; j <= n; j++) {
                    scanf("%d", &a);
                    sticker[i][j] = a;
                }
            }
        }

        /*
         * DP[i][j] : the max score when considering all columns
         *            until j-th column and having removed the
         *            sticker at (i, j).
         */
        // DP initialization
        dp[1][1] = sticker[1][1];
        dp[2][1] = sticker[2][1];
        if (n >= 2) {
            dp[1][2] = dp[2][1] + sticker[1][2];
            dp[2][2] = dp[1][1] + sticker[2][2];
        }

        for (int i = 3; i <= n; i++) {
            dp[1][i] = max(dp[2][i - 2], dp[2][i - 1]) + sticker[1][i];
            dp[2][i] = max(dp[1][i - 2], dp[1][i - 1]) + sticker[2][i];
        }

        printf("%d\n", max(dp[1][n], dp[2][n]));

        sticker.clear();
        dp.clear();
    }
    return 0;
}
