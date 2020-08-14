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

vector < vector < int > > dp;

void preprocess(int n = 29) {
    dp.resize(n + 1);

    dp[0].resize(1, 1);
    for (int i = 1; i <= n; i++) {
        dp[i].resize(i + 1);
        dp[i][0] = dp[i][i] = 1;

        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    preprocess();

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }

    return 0;
}
