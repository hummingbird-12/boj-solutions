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

constexpr int MAX = 16;
constexpr int STATUS = (1 << 16); // 2^16

/*
 * dp[status] : minimum cost required when `status` reactors are turned on.
 * i-th reactor is turned on if the i-th bit in `status` is set.
 */
int dp[STATUS];
int on_cost[MAX][MAX]; // on_cost[i][j] : cost taken to turn on j-th reactor using i-th reactor
int n, required;

bool is_on(const int& status, const int& index) {
    return (status & (1 << index)) != 0;
}

int solution(const int status, const int on_cnt) {
    if (on_cnt >= required) {
        return 0;
    }

    if (dp[status] != -1) {
        return dp[status];
    }

    dp[status] = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (is_on(status, i)) {
            for (int j = 0; j < n; j++) {
                if (!is_on(status, j)) {
                    const int new_status = status + (1 << j);

                    dp[status] = min(dp[status],
                        on_cost[i][j] + solution(new_status, on_cnt + 1));
                }
            }
        }
    }

    return dp[status];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> on_cost[i][j];
        }
    }

    int status = 0, cnt = 0;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'Y') {
            status += (1 << i);
            cnt++;
        }
    }

    cin >> required;

    if (cnt == 0 && required != 0) {
        cout << -1 << '\n';
        return 0;
    }

    fill(dp, dp + STATUS, -1);
    cout << solution(status, cnt) << '\n';

    return 0;
}
