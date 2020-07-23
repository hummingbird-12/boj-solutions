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

constexpr int MAX = 100000;

int dp[MAX][2];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    vector < int > v;

    cin >> n;
    v.resize(n);

    cin >> v[0];
    dp[0][0] = dp[0][1] = v[0];

    for (int i = 1; i < n; i++) {
        cin >> v[i];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][1] + v[i], v[i]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';

    return 0;
}
