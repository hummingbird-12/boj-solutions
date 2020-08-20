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

constexpr int MAX = 1001;

char arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '1') {
                dp[i][j] = 1;

                for (
                    int k = 1;
                    k <= dp[i - 1][j - 1] &&
                    arr[i][j - k] == '1' &&
                    arr[i - k][j] == '1';
                    k++, dp[i][j]++) {
                }

                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans * ans << '\n';

    return 0;
}
