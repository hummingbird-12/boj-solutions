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

short dp[11][11];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}
