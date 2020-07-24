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

constexpr int MOD = 1'000'000'007;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector < int > dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] + (i - m >= 0 ? dp[i - m] : 0)) % MOD;
    }

    cout << dp[n] << '\n';

    return 0;
}
