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

constexpr int MAX = 301;

/*
 * dp[i][0] : Max score obtained when came from (i - 1)th stair
 * dp[i][1] : Max score obtained when came from (i - 2)th stair
 */
int dp[MAX][2];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int score;

    cin >> score;
    dp[1][0] = dp[1][1] = score;

    if (n > 1) {
        cin >> score;
        dp[2][0] = dp[1][0] + score;
        dp[2][1] = score;
    }

    for (int i = 3; i <= n; i++) {
        cin >> score;
        dp[i][0] = dp[i - 1][1] + score;
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + score;
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}
